// license:BSD-3-Clause
// copyright-holders:Carl
// TODO: dump 8049 mcu; key repeat; LEDs

#include "emu.h"
#include "machine/qx10kbd.h"

#include "machine/keyboard.ipp"


qx10_keyboard_device::qx10_keyboard_device(const machine_config& mconfig, const char* tag, device_t* owner, uint32_t clock)
	: buffered_rs232_device(mconfig, QX10_KEYBOARD, "QX10 Keyboard", tag, owner, 0, "qx10_keyboard", __FILE__)
	, device_matrix_keyboard_interface(mconfig, *this, "LINE0", "LINE1", "LINE2", "LINE3", "LINE4", "LINE5", "LINE6", "LINE7", "LINE8", "LINE9", "LINEA", "LINEB", "LINEC", "LINED", "LINEE", "LINEF")
{
}


void qx10_keyboard_device::device_reset()
{
	buffered_rs232_device::device_reset();

	reset_key_state();
	clear_fifo();

	set_data_frame(1, 8, PARITY_EVEN, STOP_BITS_1);
	set_rate(1'200);
	receive_register_reset();
	transmit_register_reset();

	output_dcd(0);
	output_dsr(0);
	output_cts(0);
	output_rxd(1);

	start_processing(attotime::from_hz(2'400));
}


void qx10_keyboard_device::device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr)
{
	device_matrix_keyboard_interface::device_timer(timer, id, param, ptr);
	buffered_rs232_device::device_timer(timer, id, param, ptr);
}


void qx10_keyboard_device::key_make(uint8_t row, uint8_t column)
{
	transmit_byte((column << 4) | row);
}


void qx10_keyboard_device::received_byte(uint8_t data)
{
	switch (data & 0xe0)
	{
	case 0x00: // set repeat start
		break;
	case 0x20: // set repeat interval
		break;
	case 0x40: // set LED
		break;
	case 0x60: // get LED
		transmit_byte(0);
		break;
	case 0x80: // get SW
		break;
	case 0xa0: // set repeat
		break;
	case 0xc0: // enable keyboard
		break;
	case 0xe0:
		if (!(data & 1))
			transmit_byte(0);
		break;
	}
}


static INPUT_PORTS_START( qx10_keyboard )
	PORT_START("LINE0")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("RSHIFT")
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("LSHIFT") PORT_CODE(KEYCODE_LSHIFT)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("RCTRL") PORT_CODE(KEYCODE_RCONTROL)
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("GRPH SHIFT")
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("LCTRL") PORT_CODE(KEYCODE_LCONTROL)

	PORT_START("LINE1")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F4/UNDO") PORT_CODE(KEYCODE_F4)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("CAPS LOCK/(H6)") PORT_CODE(KEYCODE_CAPSLOCK)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("TAB REL")
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("Q") PORT_CODE(KEYCODE_Q) PORT_CHAR('Q')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("2") PORT_CODE(KEYCODE_2) PORT_CHAR('2')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F3/COPY DISK") PORT_CODE(KEYCODE_F3)

	PORT_START("LINE2")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F5/(H1)") PORT_CODE(KEYCODE_F5)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("SPACE") PORT_CODE(KEYCODE_SPACE) PORT_CHAR(' ')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("SHIFT LOCK")
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("W") PORT_CODE(KEYCODE_W) PORT_CHAR('W')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("3") PORT_CODE(KEYCODE_3) PORT_CHAR('3')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F2/HELP") PORT_CODE(KEYCODE_F2)

	PORT_START("LINE3")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F6/STORE") PORT_CODE(KEYCODE_F6)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("Z") PORT_CODE(KEYCODE_Z) PORT_CHAR('Z')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("A") PORT_CODE(KEYCODE_A) PORT_CHAR('A')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("E") PORT_CODE(KEYCODE_E) PORT_CHAR('E')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("4") PORT_CODE(KEYCODE_4) PORT_CHAR('4')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F1/STOP") PORT_CODE(KEYCODE_F1)

	PORT_START("LINE4")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F7/RETRIEVE") PORT_CODE(KEYCODE_F7)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_UNUSED)
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("X") PORT_CODE(KEYCODE_X) PORT_CHAR('X')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("S") PORT_CODE(KEYCODE_S) PORT_CHAR('S')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("R") PORT_CODE(KEYCODE_R) PORT_CHAR('R')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("5") PORT_CODE(KEYCODE_5) PORT_CHAR('5')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("MAR SEL")

	PORT_START("LINE5")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F8/PRINT") PORT_CODE(KEYCODE_F8)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("ENTER (PAD)") PORT_CODE(KEYCODE_ENTER_PAD)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("3 (PAD)") PORT_CODE(KEYCODE_3_PAD) PORT_CHAR('3')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("C") PORT_CODE(KEYCODE_C) PORT_CHAR('C')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("D") PORT_CODE(KEYCODE_D) PORT_CHAR('D')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("T") PORT_CODE(KEYCODE_T) PORT_CHAR('T')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("6") PORT_CODE(KEYCODE_6) PORT_CHAR('6')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("ESC/^") PORT_CODE(KEYCODE_ESC)

	PORT_START("LINE6")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F9/INDEX") PORT_CODE(KEYCODE_F9)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME(". (PAD)") PORT_CODE(KEYCODE_DEL_PAD)
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("2 (PAD)") PORT_CODE(KEYCODE_2_PAD) PORT_CHAR('2')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("V") PORT_CODE(KEYCODE_V) PORT_CHAR('V')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F") PORT_CODE(KEYCODE_F) PORT_CHAR('F')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("Y") PORT_CODE(KEYCODE_Y) PORT_CHAR('Y')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("7") PORT_CODE(KEYCODE_7) PORT_CHAR('7')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("1") PORT_CODE(KEYCODE_1) PORT_CHAR('1')

	PORT_START("LINE7")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("F10/MAIL") PORT_CODE(KEYCODE_F10)
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("0 (PAD)") PORT_CODE(KEYCODE_0_PAD) PORT_CHAR('0')
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("1 (PAD)") PORT_CODE(KEYCODE_1_PAD) PORT_CHAR('1')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("B") PORT_CODE(KEYCODE_B) PORT_CHAR('B')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("G") PORT_CODE(KEYCODE_G) PORT_CHAR('G')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("U") PORT_CODE(KEYCODE_U) PORT_CHAR('U')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("8") PORT_CODE(KEYCODE_8) PORT_CHAR('8')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("TAB") PORT_CODE(KEYCODE_TAB)

	PORT_START("LINE8")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("(H2)")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("= (PAD)")
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("+ (PAD)") PORT_CODE(KEYCODE_PLUS_PAD) PORT_CHAR('+')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("N") PORT_CODE(KEYCODE_N) PORT_CHAR('N')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("H") PORT_CODE(KEYCODE_H) PORT_CHAR('H')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("I") PORT_CODE(KEYCODE_I) PORT_CHAR('I')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("9") PORT_CODE(KEYCODE_9) PORT_CHAR('9')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("TAB SET")

	PORT_START("LINE9")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("BREAK/MENU")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("6 (PAD)") PORT_CODE(KEYCODE_6_PAD) PORT_CHAR('6')
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("9 (PAD)") PORT_CODE(KEYCODE_9_PAD) PORT_CHAR('9')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("M") PORT_CODE(KEYCODE_M) PORT_CHAR('M')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("J") PORT_CODE(KEYCODE_J) PORT_CHAR('J')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("O") PORT_CODE(KEYCODE_O) PORT_CHAR('O')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("0") PORT_CODE(KEYCODE_0) PORT_CHAR('0')
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINEA")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("PAUSE/CALC")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("5 (PAD)") PORT_CODE(KEYCODE_5_PAD) PORT_CHAR('5')
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("8 (PAD)") PORT_CODE(KEYCODE_8_PAD) PORT_CHAR('8')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME(",")
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("K") PORT_CODE(KEYCODE_K) PORT_CHAR('K')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("P") PORT_CODE(KEYCODE_P) PORT_CHAR('P')
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("-")
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINEB")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("SCRN DUMP/SCHED")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("4 (PAD)") PORT_CODE(KEYCODE_4_PAD) PORT_CHAR('4')
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("7 (PAD)") PORT_CODE(KEYCODE_7_PAD) PORT_CHAR('7')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME(".") PORT_CODE(KEYCODE_STOP) PORT_CHAR('.')
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("L") PORT_CODE(KEYCODE_L) PORT_CHAR('L')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("@/1/2 1/4")
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("=")
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINEC")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("HELP/DRAW")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("(H5)")
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("- (PAD)") PORT_CODE(KEYCODE_MINUS_PAD) PORT_CHAR('-')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("UP") PORT_CODE(KEYCODE_UP)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME(";") PORT_CODE(KEYCODE_COLON) PORT_CHAR(';')
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("</[")
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("\\") PORT_CODE(KEYCODE_BACKSLASH)
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINED")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("(H3)")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("MF4/(H4)")
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("* (PAD)") PORT_CODE(KEYCODE_ASTERISK) PORT_CHAR('*')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("LEFT") PORT_CODE(KEYCODE_LEFT)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("9-6")
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME(">/]")
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("BACKSPACE") PORT_CODE(KEYCODE_BACKSPACE)
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINEE")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("BOLD")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("MF3/STYLE")
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("/ (PAD)") PORT_CODE(KEYCODE_SLASH_PAD) PORT_CHAR('/')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("RIGHT") PORT_CODE(KEYCODE_RIGHT)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("RETURN") PORT_CODE(KEYCODE_ENTER) PORT_CHAR(0x0d)
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("INSERT") PORT_CODE(KEYCODE_INSERT)
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("D-7")
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)

	PORT_START("LINEF")
	PORT_BIT(0x01,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("MF1/ITALIC")
	PORT_BIT(0x02,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("MF2/SIZE")
	PORT_BIT(0x04,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("`/DEC TAB") PORT_CODE(KEYCODE_TILDE) PORT_CHAR('`')
	PORT_BIT(0x08,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("DOWN") PORT_CODE(KEYCODE_DOWN)
	PORT_BIT(0x10,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("? /")
	PORT_BIT(0x20,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("DEL/WORD") PORT_CODE(KEYCODE_DEL) PORT_CHAR(UCHAR_MAMEKEY(DEL))
	PORT_BIT(0x40,IP_ACTIVE_HIGH,IPT_KEYBOARD) PORT_NAME("CLS/LINE")
	PORT_BIT(0x80,IP_ACTIVE_HIGH,IPT_UNUSED)
INPUT_PORTS_END

ioport_constructor qx10_keyboard_device::device_input_ports() const
{
	return INPUT_PORTS_NAME(qx10_keyboard);
}


const device_type QX10_KEYBOARD = &device_creator<qx10_keyboard_device>;
