// license:BSD-3-Clause
// copyright-holders:Michael Zapf
/****************************************************************************

    Hexbus floppy disk drive
    HX5102

    Memory map
    0000 - 1FFF: ROM1 (8 KiB, circuit u25, EPROM 2564)
    2000 - 3FFF: ROM2 (8 KiB, circuit u29, EPROM 2564)
    4000 - DFFF: Mirrors of ROM1/ROM2
    E000 - EFFF: SRAM (4 KiB)
    F000 - F0F9: On-Chip RAM (TMS9995)
    F7E0 - F7EF: Memory-mapped access to NEC uPD765 / Intel 8272A
    F7F0 - F7FF: Memory-mapped access to IBC
    F800 - FFF9: Unmapped
    FFFA - FFFF: On-Chip RAM (TMS9995)

    NEC uPD765 / Intel 8272A
    F7E0 R    Main status register (MSR)
    F7E4 R    Data register (FIFO read)
    F7E8 W    Command register (FIFO write)

    Supporting circuitry
    F7E2 R    DMA read
    F7E6 -    -
    F7EA W    DMA write
    F7EC W    Ready lock
    F7EE -    -

    Intelligent Bus Controller (Hexbus)
    F7F0 R   Received data
    F7F2 R   Status register
    F7F4 -
    F7F6 -
    F7F8 W   Transmit data
    F7FA W   Control register
    F7FC -
    F7FE -

    Ports (CRU bit): read
    17E0 (0): Controller INT line
    17E2 (1): Motor spinning (monoflop 1)
    17E4 (2): Timeout for disk operations (monoflop 2)
    17E6 (3): -
    17E8 (4): Drive 0 cylinder count (0=40, 1=77)
    17EA (5): Drive 1 cylinder count
    17EC (6): Drive 2 cylinder count
    17EE (7): Drive 3 cylinder count

    Ports (CRU bit): write
    17E0 (0): Precompensation
    17E2 (1): Motor trigger
    17E4 (2): -
    17E6 (3): Step dir (1=inwards)
    17E8 (4): When 1, assert DACK* (set to 0)
    17EA (5): Step pulse (up)
    17EC (6): Timeout flipflop trigger
    17EE (7): RESET* the controller (goes to RESET input, inverted)
    17F0 (8): Drive select drive 0 (DSK1)
    17F2 (9): Drive select drive 1 (DSK2)
    17F4 (10): Drive select drive 2 (DSK3)
    17F6 (11): Drive select drive 3 (DSK4)
    17F8 (12): Separate Motor line for internal drive (not used)
    17FA (13): Not connected; turned on before sector I/O, format track, reset drives; turned off once when reporting status
    17FC (14): Arm READY circuit
    17FE (15): Not connected; possibly in test mode only

    Michael Zapf
    March 2018

*****************************************************************************/

#include "emu.h"
#include "hx5102.h"
#include "formats/ti99_dsk.h"

#define LOG_HEXBUS         (1U<<1)   // Hexbus operation
#define LOG_RESET          (1U<<2)   // Reset
#define LOG_WARN           (1U<<3)   // Warnings
#define LOG_READY          (1U<<4)   // READY
#define LOG_SIGNALS        (1U<<5)   // IRQ/DRQ
#define LOG_CRU            (1U<<6)   // CRU
#define LOG_RAM            (1U<<7)   // RAM
#define LOG_DMA            (1U<<8)   // DMA
#define LOG_MOTOR          (1U<<9)   // Motor activity
#define LOG_STATUS         (1U<<10)  // Main status register
#define LOG_FIFO           (1U<<11)  // Data register

// Minimum log should be config and warnings
#define VERBOSE ( LOG_GENERAL | LOG_WARN )

#include "logmacro.h"

#define TMS9995_TAG   "drivecpu"
#define DSR_TAG       "dsr"
#define FDC_TAG       "i8272a"
#define IBC_TAG       "ibc_1052911"
#define MTRD_TAG      "u24_motor_mf"
#define MTSPD_TAG     "u24_motor_speed_mf"
#define READYFF_TAG   "u21_ready_ff"
#define RAM1_TAG      "u12_ram"
#define RAM2_TAG      "u19_ram"
#define ROM1_TAG      "u25_rom"
#define ROM2_TAG      "u29_rom"

#define MOTOR_TIMER 1

DEFINE_DEVICE_TYPE_NS(HX5102, bus::hexbus, hx5102_device, "ti_hx5102", "TI Hexbus Floppy Drive")

namespace bus { namespace hexbus {

ADDRESS_MAP_START(hx5102_device::memmap)
	AM_RANGE(0x0000, 0xffff) AM_READWRITE(read, write)
ADDRESS_MAP_END

/*
    CRU access to CRU addresses 1700 - 17FE)
*/
ADDRESS_MAP_START(hx5102_device::crumap)
	AM_RANGE(0x17e0>>4,0x17fe>>4) AM_READ(cruread)
	AM_RANGE(0x17e0>>1,0x17fe>>1) AM_WRITE(cruwrite)
ADDRESS_MAP_END

hx5102_device::hx5102_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock):
	hexbus_chained_device(mconfig, HX5102, tag, owner, clock),
	m_flopcpu(*this, TMS9995_TAG),
	m_ready_old(CLEAR_LINE),
	m_motor_on(false),
	m_mspeed_on(false),
	m_pending_int(false),
	m_dcs(false),
	m_dack(false),
	m_dacken(false),
	m_wait(false),
	m_hexbus_ctrl(*this, IBC_TAG),
	m_floppy_ctrl(*this, FDC_TAG),
	m_motormf(*this, MTRD_TAG),
	m_speedmf(*this, MTSPD_TAG),
	m_readyff(*this, READYFF_TAG),
	m_ram1(*this, RAM1_TAG),
	m_ram2(*this, RAM2_TAG)
{
}

WRITE8_MEMBER( hx5102_device::external_operation )
{
	static const char* extop[8] = { "inv1", "inv2", "IDLE", "RSET", "inv3", "CKON", "CKOF", "LREX" };
	if (offset != IDLE_OP) LOGMASKED(LOG_WARN, "External operation %s not implemented on HX5102 board\n", extop[offset]);
}


/*
    Read operation. We cannot use the convenient address maps because the
    READY circuit requires a flag created from the address lines (m_dcs) which
    must be reset on accesses outside of the i8272a memory mapping area.

    V1 = A0 & A1 (A0=MSB)                      11.. .... .... ....
    V2 = A4* & A5 & A6 & A7 & A8 & A9 & A10    .... 0111 111. ....

    PAL equations
    ROM1 = MEM & V1* & A2* & WE* = 0000..1FFF, 4000..5FFF, 8000..9FFF
    ROM2 = MEM & V1* & A2 & WE*  = 2000..3FFF, 6000..7FFF, A000..BFFF
    RAM = MEM & V1 & A2 & A3*    = E000..EFFF
    DCS = MEM & V1 & A2 & A3 & A15* & V2 & A11* & A14*              = F7E0,F7E4,F7E8,F7EC
    HCS = MEM & V1 & A2 & A3 & A15* & V2 & A11 & A13*               = F7F0,F7F2,F7F8,F7FA
    DACK = MEM & V1 & A2 & A3 & A15* & V2 & A11* & A13* & A14       = F7E2,F7EA
    AZ = MEM & V1 & A2 & A3 & A15* & V2 & A11* & A12* & A13* & A14* = F7E0
    CRU = MEM* & V1* & A2* & A3 & V2                                = 17E0..17FE
    RD = MEM & V1 & A2 & A3 & A15* & V2 & A12* & DBIN               = F7E0,F7E2,F7E4,F7E6,F7F0,F7F2,F7F4,F7F6
        | MEM & V1 & A2 & A3* & DBIN                               = E000-EFFF
    WR = MEM & V1 & A2 & A3 & A15* & V2 & A12 & A13* & WE           = F7E8,F7EA,F7F8,F7FA
        | MEM & V1 & A2 & A3* & WE                                 = E000-EFFF

*/

/*
    Reading from the address space of the drive.
*/
READ8_MEMBER( hx5102_device::read )
{
	bool ramen1 = ((offset & 0xf800)==0xe000);
	bool ramen2 = ((offset & 0xf800)==0xe800);
	bool romen1 = ((offset & 0xc000)!=0xc000) && ((offset & 0x2000)==0);
	bool romen2 = ((offset & 0xc000)!=0xc000) && ((offset & 0x2000)!=0);
	bool hcs = ((offset & 0xfff5)==0xf7f0);

	m_dcs = ((offset & 0xfff3)==0xf7e0);
	m_dack = ((offset & 0xfff7)==0xf7e2);

	// RAM 1
	uint8_t val;
	if (ramen1)
	{
		val = m_ram1->pointer()[offset & 0x07ff];
		LOGMASKED(LOG_RAM, "RAM %04x -> %02x\n", (offset & 0x07ff)|0xe000, val);
		return val;
	}

	// RAM 2
	if (ramen2)
	{
		val = m_ram2->pointer()[offset & 0x07ff];
		LOGMASKED(LOG_RAM, "RAM %04x -> %02x\n", (offset & 0x07ff)|0xe800, val);
		return val;
	}

	// ROM 1
	if (romen1)
		return m_rom1[offset & 0x1fff];

	// ROM 2
	if (romen2)
		return m_rom2[offset & 0x1fff];

	// Floppy drive controller
	if (m_dcs)
		return fdc_read(space, offset&0x000f);

	// Hexbus controller
	if (hcs)
		return ibc_read(space, offset&0x000f);

	// DMA
	if (m_dack)
	{
		// Pick DMA byte from the controller; this automatically signals DACK*
		// Thus the drive CPU is the target for the DMA transfer
		uint8_t val = m_floppy_ctrl->dma_r();
		LOGMASKED(LOG_DMA, "i8272a.dma -> %02x '%c'\n", val, (val>33 && val<127)? val : '.');
		return val;
	}

	if ((offset & 1)==0) LOGMASKED(LOG_WARN, "Unmapped read access: %04x\n", offset);
	return 0;
}

/*
    Writing into the address space of the drive.
*/
WRITE8_MEMBER( hx5102_device::write )
{
	bool ramen1 = ((offset & 0xf800)==0xe000);
	bool ramen2 = ((offset & 0xf800)==0xe800);
	bool hcs = ((offset & 0xfff5)==0xf7f0);
	m_dcs = ((offset & 0xfff3)==0xf7e0);
	m_dack = ((offset & 0xfff7)==0xf7e2);

	// RAM 1
	if (ramen1)
	{
		LOGMASKED(LOG_RAM, "RAM %04x <- %02x\n", (offset & 0x07ff)|0xe000, data);
		m_ram1->pointer()[offset & 0x07ff] = data;
		return;
	}

	// RAM 2
	if (ramen2)
	{
		LOGMASKED(LOG_RAM, "RAM %04x <- %02x\n", (offset & 0x07ff)|0xe800, data);
		m_ram2->pointer()[offset & 0x07ff] = data;
		return;
	}

	// Floppy drive controller
	if (m_dcs)
	{
		fdc_write(space, offset&0x000f, data);
		return;
	}

	// Hexbus controller
	if (hcs)
	{
		ibc_write(space, offset&0x000f, data);
		return;
	}

	// DMA
	if (m_dack)
	{
		m_floppy_ctrl->dma_w(data);
		LOGMASKED(LOG_DMA, "i8272a.dma <- %02x '%c'\n", data, (data>33 && data<127)? data : '.');
		return;
	}

	if ((offset & 1)==0) LOGMASKED(LOG_WARN, "Unmapped write access: %04x\n", offset);
}


/*
    Clock line from the CPU. Used to control wait state generation.
*/
WRITE_LINE_MEMBER( hx5102_device::clock_out )
{
	m_readyff->clock_w(state);
}

/*
    Input from the Hexbus
*/
void hx5102_device::hexbus_value_changed(uint8_t data)
{
	m_hexbus_ctrl->from_hexbus(data);
}

/*
    Propagate READY signals to the CPU. This is used to hold the CPU
    during DMA accesses.
*/
WRITE_LINE_MEMBER( hx5102_device::board_ready )
{
	if (m_ready_old != state)
	{
		LOGMASKED(LOG_READY, "READY = %d\n", state);
	}

	m_ready_old = (line_state)state;
	m_flopcpu->ready_line(state);
}

/*
    Trigger RESET.
*/
WRITE_LINE_MEMBER( hx5102_device::board_reset )
{
	LOGMASKED(LOG_RESET, "Incoming RESET line = %d\n", state);

	if (machine().phase() != machine_phase::INIT)
	{
		// Setting ready to true so that automatic wait states are disabled
		m_flopcpu->ready_line(ASSERT_LINE);
		m_flopcpu->reset_line(ASSERT_LINE);
	}
}

/*
    Effect from the motor monoflop.
*/
WRITE_LINE_MEMBER( hx5102_device::motor_w )
{
	m_motor_on = (state==ASSERT_LINE);
	LOGMASKED(LOG_MOTOR, "Motor %s\n", m_motor_on? "start" : "stop");
	m_floppy->mon_w(m_motor_on? 0 : 1);
	update_readyff_input();
}

/*
    Effect from the speed monoflop. This is essentially a watchdog to
    check whether the lock on the CPU must be released due to an error.
*/
WRITE_LINE_MEMBER( hx5102_device::mspeed_w )
{
	m_mspeed_on = (state==ASSERT_LINE);
	LOGMASKED(LOG_READY, "Speedcheck %s\n", m_mspeed_on? "on" : "off");
	update_readyff_input();
}

/*
    Read access to the floppy controller
*/
READ8_MEMBER(hx5102_device::fdc_read)
{
	uint8_t val = 0;
	switch (offset)
	{
	case 0:
		// Main status register
		val = m_floppy_ctrl->msr_r();
		LOGMASKED(LOG_STATUS, "i8272A.msr -> %02x\n", val);
		break;
	case 4:
		// FIFO read
		val = m_floppy_ctrl->fifo_r();
		LOGMASKED(LOG_FIFO, "i8272A.fifo -> %02x\n", val);
		break;
	}
	return val;
}

/*
    Write access to the floppy controller
*/
WRITE8_MEMBER(hx5102_device::fdc_write)
{
	m_dcs = ((offset & 0x0003)==0);

	switch (offset)
	{
	case 0x08:
		// Command register (FIFO write)
		LOGMASKED(LOG_STATUS, "i8272A.fifo <- %02x\n", data);
		m_floppy_ctrl->fifo_w(data);
		break;
	case 0x0c:
		// DMA lock
		LOGMASKED(LOG_READY, "Lock READY\n", data);
		update_readyff_input();
		break;
	}
}

void hx5102_device::update_readyff_input()
{
	LOGMASKED(LOG_READY, "MON=%d, MSP=%d, WAIT=%d, INT*=%d, DRQ*=%d, DCS=%d\n", m_motor_on, m_mspeed_on, m_wait, !m_pending_int, !m_pending_drq, m_dcs);
	m_readyff->d_w(m_motor_on && m_mspeed_on && m_wait && !m_pending_int && !m_pending_drq && m_dcs);
}

/*
    Access to the Hexbus controller
*/
READ8_MEMBER(hx5102_device::ibc_read)
{
	if ((offset & 1)==0)
		return m_hexbus_ctrl->read(space, (offset>>1)&1);
	else
		return 0;
}

WRITE8_MEMBER(hx5102_device::ibc_write)
{
	if ((offset & 1)==0)
		m_hexbus_ctrl->write(space, (offset>>1)&1, data);
}

WRITE8_MEMBER(hx5102_device::hexbus_out)
{
	LOGMASKED(LOG_HEXBUS, "hexbus out: %02x\n", data);

	// Get the other levels and set our own states
	uint8_t newlevel = hexbus_get_levels() & data;
	m_hexbus_ctrl->update_lines((newlevel & 0x04)==0, (newlevel & 0x10)==0);

	// Now set the bus. This may entail further changes, incoming via hexbus_value_changed.
	hexbus_write(data);
}

/*
    Latch the HSK* to low.
*/
WRITE_LINE_MEMBER(hx5102_device::hsklatch_out)
{
	LOGMASKED(LOG_HEXBUS, "Latching HSK*\n");
	m_myvalue &= ~HEXBUS_LINE_HSK;
}

/*
    CRU read access.

      7     6     5     4     3     2     1     0
    +-----+-----+-----+-----+-----+-----+-----+-----+
    | TD3 | TD2 | TD1 | TD0 |  0  | TIM | MON | INT |
    +-----+-----+-----+-----+-----+-----+-----+-----+

    TDx = Tracks for drive x; 0 = 40, 1 = 77
    TIM = Timeout
    MON = Motor on
    INT = Interrupt from i8272A
*/
READ8_MEMBER(hx5102_device::cruread)
{
	uint8_t crubits = 0;
	// LOGMASKED(LOG_CRU, "Reading CRU addresses %04x-%04x\n", 0x17e0 + (offset<<4), 0x17ee + (offset<<4));
	if (m_pending_int) crubits |= 0x01;
	if (m_motor_on) crubits |= 0x02;
	if (m_mspeed_on) crubits |= 0x04;
	return crubits;
}

/*
    CRU write access.
*/
WRITE8_MEMBER(hx5102_device::cruwrite)
{
	// LOG("Writing CRU address %04x: %x\n", 0x17e0 + (offset<<1), data);
	switch (offset)
	{
	case 0:
		// unused right now
		LOGMASKED(LOG_CRU, "Set precompensation = %d\n", data);
		break;
	case 1:
		if (data==1)
		{
			LOGMASKED(LOG_CRU, "Trigger motor monoflop\n");
		}
		m_motormf->b_w(data);
		break;
	case 2:
		LOGMASKED(LOG_CRU, "Set undefined CRU bit 2 to %d\n", data);
		break;
	case 3:
		LOGMASKED(LOG_CRU, "Set step direction = %d\n", data);
		m_floppy->dir_w((data==0)? 1 : 0);
		break;
	case 4:
		if (data==1)
		{
			LOGMASKED(LOG_CRU, "Assert DACK*\n");
			m_dacken = (data != 0);
		}
		break;
	case 5:
		if (data==1)
		{
			LOGMASKED(LOG_CRU, "Step pulse\n");
		}
		m_floppy->stp_w((data==0)? 1 : 0);
		break;
	case 6:
		if (data==1)
		{
			LOGMASKED(LOG_CRU, "Start watchdog\n");
		}
		m_speedmf->b_w(data);
		break;
	case 7:
		if (data==0)
		{
			LOGMASKED(LOG_CRU, "Reset i8272A controller\n");
			m_floppy_ctrl->soft_reset();
		}
		break;
	case 8:
		LOGMASKED(LOG_CRU, "Set drive select 0 to %d\n", data);
		m_floppy_ctrl->set_floppy((data==1)? m_floppy : nullptr);
		break;
	case 9:
		// External drive; not implemented
		LOGMASKED(LOG_CRU, "Set drive select 1 to %d\n", data);
		break;
	case 10:
		// External drive; not implemented
		LOGMASKED(LOG_CRU, "Set drive select 2 to %d\n", data);
		break;
	case 11:
		// External drive; not implemented
		LOGMASKED(LOG_CRU, "Set drive select 3 to %d\n", data);
		break;
	case 12:
		// External drive; not implemented
		LOGMASKED(LOG_CRU, "Set auxiliary motor line to %d\n", data);
		break;
	case 13:
		LOGMASKED(LOG_CRU, "Set CRU bit 13 to %d (unused)\n", data);
		break;
	case 14:
		m_wait = (data!=0);
		LOGMASKED(LOG_CRU, "READY circuit %s\n", m_wait? "active" : "inactive" );
		update_readyff_input();
		break;
	case 15:
		LOGMASKED(LOG_CRU, "Set CRU bit 15 to %d (unused)\n", data);
		break;
	}
}

/*
    Device lifecycle.
*/
void hx5102_device::device_start()
{
	m_floppy = static_cast<floppy_image_device*>(subdevice("d0")->subdevices().first());

	m_rom1 = (uint8_t*)memregion(DSR_TAG)->base();
	m_rom2 = (uint8_t*)memregion(DSR_TAG)->base() + 0x2000;
}

/*
    Device lifecycle.
*/
void hx5102_device::device_reset()
{
	board_reset(ASSERT_LINE);
	board_ready(ASSERT_LINE);
}

/*
    Callbacks from the i8272A chip
    Interrupt
*/
WRITE_LINE_MEMBER( hx5102_device::fdc_irq_w )
{
	line_state irq = state? ASSERT_LINE : CLEAR_LINE;
	LOGMASKED(LOG_SIGNALS, "INTRQ callback = %d\n", irq);
	m_pending_int = state;
	update_readyff_input();
}

/*
    Callbacks from the i8272A chip
    DMA request
*/
WRITE_LINE_MEMBER( hx5102_device::fdc_drq_w )
{
	line_state drq = state? ASSERT_LINE : CLEAR_LINE;
	LOGMASKED(LOG_SIGNALS, "DRQ callback = %d\n", drq);
	m_pending_drq = state;
	update_readyff_input();
}

/*
    Define the floppy formats.
    TODO: Define another DSDD format with 16 sectors.
*/
FLOPPY_FORMATS_MEMBER(hx5102_device::floppy_formats)
	FLOPPY_TI99_SDF_FORMAT,
	FLOPPY_TI99_TDF_FORMAT
FLOPPY_FORMATS_END

/*
    Only one fixed floppy drive in the device.
    External connectors are available, though.
*/
static SLOT_INTERFACE_START( hx5102_drive )
	SLOT_INTERFACE( "525dd", FLOPPY_525_DD )
SLOT_INTERFACE_END

/*
    HX5102 configuration
*/
MACHINE_CONFIG_START(hx5102_device::device_add_mconfig)
	// Hexbus controller
	MCFG_DEVICE_ADD(IBC_TAG, IBC, 0)
	MCFG_IBC_HEXBUS_OUT_CALLBACK(WRITE8(hx5102_device, hexbus_out))
	MCFG_IBC_HSKLATCH_CALLBACK(WRITELINE(hx5102_device, hsklatch_out))

	// Outgoing socket for downstream devices
	MCFG_HEXBUS_ADD("hexbus")

	// TMS9995 CPU @ 12.0 MHz
	MCFG_TMS99xx_ADD(TMS9995_TAG, TMS9995, XTAL(12'000'000), memmap, crumap)
	MCFG_TMS9995_EXTOP_HANDLER( WRITE8(hx5102_device, external_operation) )
	MCFG_TMS9995_CLKOUT_HANDLER( WRITELINE(hx5102_device, clock_out) )

	// Disk controller i8272A
	// Not connected: Select lines (DS0, DS1), Head load (HDL), VCO
	// Tied to 1: READY
	// Tied to 0: TC
	MCFG_I8272A_ADD(FDC_TAG, false)
	MCFG_UPD765_INTRQ_CALLBACK(WRITELINE(hx5102_device, fdc_irq_w))
	MCFG_UPD765_DRQ_CALLBACK(WRITELINE(hx5102_device, fdc_drq_w))
	MCFG_FLOPPY_DRIVE_ADD("d0", hx5102_drive, "525dd", hx5102_device::floppy_formats)
	MCFG_FLOPPY_DRIVE_SOUND(true)

	// Monoflops
	MCFG_DEVICE_ADD(MTRD_TAG, TTL74123, 0)
	MCFG_TTL74123_CONNECTION_TYPE(TTL74123_GROUNDED)
	MCFG_TTL74123_RESISTOR_VALUE(RES_K(200))
	MCFG_TTL74123_CAPACITOR_VALUE(CAP_U(47))
	MCFG_TTL74123_A_PIN_VALUE(0)
	MCFG_TTL74123_B_PIN_VALUE(1)
	MCFG_TTL74123_CLEAR_PIN_VALUE(1)
	MCFG_TTL74123_OUTPUT_CHANGED_CB(WRITELINE(hx5102_device, motor_w))

	MCFG_DEVICE_ADD(MTSPD_TAG, TTL74123, 0)
	MCFG_TTL74123_CONNECTION_TYPE(TTL74123_GROUNDED)
	MCFG_TTL74123_RESISTOR_VALUE(RES_K(200))
	MCFG_TTL74123_CAPACITOR_VALUE(CAP_U(10))
	MCFG_TTL74123_A_PIN_VALUE(0)
	MCFG_TTL74123_B_PIN_VALUE(1)
	MCFG_TTL74123_CLEAR_PIN_VALUE(1)
	MCFG_TTL74123_OUTPUT_CHANGED_CB(WRITELINE(hx5102_device, mspeed_w))

	// READY flipflop
	MCFG_DEVICE_ADD(READYFF_TAG, TTL7474, 0)
	MCFG_7474_COMP_OUTPUT_CB(WRITELINE(hx5102_device, board_ready))

	// RAM
	MCFG_RAM_ADD(RAM1_TAG)
	MCFG_RAM_DEFAULT_SIZE("2048")
	MCFG_RAM_DEFAULT_VALUE(0)

	MCFG_RAM_ADD(RAM2_TAG)
	MCFG_RAM_DEFAULT_SIZE("2048")
	MCFG_RAM_DEFAULT_VALUE(0)

MACHINE_CONFIG_END

ROM_START( hx5102 )
	ROM_REGION( 0x4000, DSR_TAG, 0 )
	ROM_LOAD( "hx5102_rom1.u25", 0x0000, 0x2000, CRC(40621a77) SHA1(1532f6f23e0104326c21909cb0ec46936242a12a) )
	ROM_LOAD( "hx5102_rom2.u29", 0x2000, 0x2000, CRC(57c2603b) SHA1(2f1d01378943436f0abd5b20710f6c8c175fde13) )
ROM_END

const tiny_rom_entry *hx5102_device::device_rom_region() const
{
	return ROM_NAME( hx5102 );
}

}   }  // end namespace bus::hexbus

