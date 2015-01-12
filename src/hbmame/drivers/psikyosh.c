#include "../mame/drivers/psikyosh.c"

ROM_START( s1945iiex )
	ROM_REGION( 0x200000, "maincpu", 0) /* Code */
	ROM_LOAD32_WORD_SWAP( "2_prog_l.u18-ex", 0x000002, 0x080000, CRC(56276eb7) SHA1(28530132058621382697c678426967d720741853) )
	ROM_LOAD32_WORD_SWAP( "1_prog_h.u17-ex", 0x000000, 0x080000, CRC(99658d0d) SHA1(f8b7a697819dc1e4993557d9e854aa53964eb4a3) )

	ROM_REGION( 0x2000000, "gfx1", 0 )  /* Tiles */
	ROM_LOAD32_WORD( "0l.u4",    0x0000000, 0x400000, CRC(bfacf98d) SHA1(19954f12881e6e95e808bd1f2c2f5a425786727f) )
	ROM_LOAD32_WORD( "0h.u13",   0x0000002, 0x400000, CRC(1266f67c) SHA1(cf93423a827aa92aa54afbbecf8509d2590edc9b) )
	ROM_LOAD32_WORD( "1l.u3",    0x0800000, 0x400000, CRC(2d3332c9) SHA1(f2e54100a48061bfd589e8765f59ca051176a38b) )
	ROM_LOAD32_WORD( "1h.u12",   0x0800002, 0x400000, CRC(27b32c3e) SHA1(17a80b3c919d8a282169c019ede8a22d2079c018) )
	ROM_LOAD32_WORD( "2l.u2",    0x1000000, 0x400000, CRC(91ba6d23) SHA1(fd016a90204b2de43bb709971f7cd891f839de1a) )
	ROM_LOAD32_WORD( "2h.u20",   0x1000002, 0x400000, CRC(fabf4334) SHA1(f8ec43e083b674700f532575f0d067bd49c5aaf7) )
	ROM_LOAD32_WORD( "3l.u1",    0x1800000, 0x400000, CRC(a6c3704e) SHA1(cb9881e4235cc8e4bcca4c6ccbd8d8d8634e3624) )
	ROM_LOAD32_WORD( "3h.u19",   0x1800002, 0x400000, CRC(4cd3ca70) SHA1(5b0a6ea4fe0e821cebe6e840596f648e24dded51) )

	ROM_REGION( 0x400000, "ymf", 0 ) /* Samples */
	ROM_LOAD( "sound.u32", 0x000000, 0x400000, CRC(ba680ca7) SHA1(b645896e297aad426784aa656bff738e1b33c2a2) )

	ROM_REGION( 0x100, "eeprom", 0 )
	ROM_LOAD( "eeprom-s1945ii.bin", 0x0000, 0x0100, CRC(7ac38846) SHA1(c5f4b05a94211f3c96b8c472adbe634f2e77d753) )
ROM_END



/*     YEAR  NAME      PARENT    MACHINE      INPUT    CLASS           INIT   MONITOR  COMPANY   FULLNAME                                FLAGS */
GAME( 2009, s1945iiex, s1945ii,  psikyo3v1,   s1945ii, psikyosh_state,  ps3,  ROT270, "Pipi899", "Strikers 1945 II (EX Super Version)", GAME_SUPPORTS_SAVE )
