#include "../mame/drivers/gauntlet.c"

ROM_START( gaunt2s )
	ROM_REGION( 0x80000, "maincpu", 0 )	/* 8*64k for 68000 code */
	ROM_LOAD16_BYTE( "136037-1307.9a",  0x000000, 0x008000, CRC(46fe8743) SHA1(d5fa19e028a2f43658330c67c10e0c811d332780) )
	ROM_LOAD16_BYTE( "136037-1308.9b",  0x000001, 0x008000, CRC(276e15c4) SHA1(7467b2ec21b1b4fcc18ff9387ce891495f4b064c) )
	ROM_LOAD16_BYTE( "136043-1105.10a", 0x038000, 0x004000, CRC(45dfda47) SHA1(a9a03150f5a0ad6ce62c5cfdffb4a9f54340590c) )
	ROM_LOAD16_BYTE( "136043-1106.10b", 0x038001, 0x004000, CRC(343c029c) SHA1(d2df4e5b036500dcc537a1e0025abb2a8c730bdd) )
	ROM_LOAD16_BYTE( "gaunt2s-1109.7a", 0x040000, 0x008000, CRC(32c909b4) SHA1(53c62d7a6660ccff4302ae9b8edcbe2949013e5e) )
	ROM_LOAD16_BYTE( "gaunt2s-1110.7b", 0x040001, 0x008000, CRC(a1a2ac12) SHA1(bd939cf97f8c4d52bedc475ee1ce00c226aee234) )
	ROM_LOAD16_BYTE( "136043-1121.6a",  0x050000, 0x008000, CRC(ae301bba) SHA1(3d93236aaffe6ef692e5073b1828633e8abf0ce4) )
	ROM_LOAD16_BYTE( "136043-1122.6b",  0x050001, 0x008000, CRC(e94aaa8a) SHA1(378c582c360440b808820bcd3be78ec6e8800c34) )

	ROM_REGION( 0x10000, "audiocpu", 0 )	/* 64k for 6502 code */
	ROM_LOAD( "136043-1120.16r", 0x004000, 0x004000, CRC(5c731006) SHA1(045ad571db34ef870b1bf003e77eea403204f55b) )
	ROM_LOAD( "136043-1119.16s", 0x008000, 0x008000, CRC(dc3591e7) SHA1(6d0d8493609974bd5a63be858b045fe4db35d8df) )

	ROM_REGION( 0x04000, "gfx1", 0 )
	ROM_LOAD( "136043-1104.6p",  0x000000, 0x002000, CRC(1343cf6f) SHA1(4a9542bc8ede305e7e8f860eb4b47ca2f3017275) )

	ROM_REGION( 0x60000, "gfx2", ROMREGION_INVERT )
	ROM_LOAD( "136043-1111.1a",  0x000000, 0x008000, CRC(09df6e23) SHA1(726984275c6a338c12ec0c4cc449f92f4a7a138c) )
	ROM_LOAD( "136037-112.1b",   0x008000, 0x008000, CRC(869330be) SHA1(5dfaaf54ee2b3c0eaf35e8c17558313db9791616) )
	ROM_LOAD( "136043-1123.1c",  0x010000, 0x004000, CRC(e4c98f01) SHA1(a24bece3196d13c38e4acdbf62783860253ba67d) )
	ROM_RELOAD(                  0x014000, 0x004000 )
	ROM_LOAD( "136043-1113.1l",  0x018000, 0x008000, CRC(33cb476e) SHA1(e0757ee0120de2d38be44f8dc8702972c35b87b3) )
	ROM_LOAD( "136037-114.1mn",  0x020000, 0x008000, CRC(29ef9882) SHA1(91e1465af6505b35cd97434c13d2b4d40a085946) )
	ROM_LOAD( "136043-1124.1p",  0x028000, 0x004000, CRC(c4857879) SHA1(3b4ce96da0d178b4bc2d05b5b51b42c7ec461113) )
	ROM_RELOAD(                  0x02c000, 0x004000 )
	ROM_LOAD( "136043-1115.2a",  0x030000, 0x008000, CRC(f71e2503) SHA1(244e108668eaef6b64c6ff733b08b9ee6b7a2d2b) )
	ROM_LOAD( "136037-116.2b",   0x038000, 0x008000, CRC(11e0ac5b) SHA1(729b7561d59d94ef33874a134b97bcd37573dfa6) )
	ROM_LOAD( "136043-1125.2c",  0x040000, 0x004000, CRC(d9c2c2d1) SHA1(185e38c75c06b6ca131a17ee3a46098279bfe17e) )
	ROM_RELOAD(                  0x044000, 0x004000 )
	ROM_LOAD( "136043-1117.2l",  0x048000, 0x008000, CRC(9e30b2e9) SHA1(e9b513089eaf3bec269058b437fefe7075a3fd6f) )
	ROM_LOAD( "136037-118.2mn",  0x050000, 0x008000, CRC(8bf3b263) SHA1(683d900ab7591ee661218be2406fb375a12e435c) )
	ROM_LOAD( "136043-1126.2p",  0x058000, 0x004000, CRC(a32c732a) SHA1(abe801dff7bb3f2712e2189c2b91f172d941fccd) )
	ROM_RELOAD(                  0x05c000, 0x004000 )

	ROM_REGION( 0x500, "proms", 0 )
	ROM_LOAD( "74s472-136037-101.7u", 0x000, 0x200, CRC(2964f76f) SHA1(da966c35557ec1b95e1c39cd950c38a19bce2d67) ) /* MO timing */
	ROM_LOAD( "74s472-136037-102.5l", 0x200, 0x200, CRC(4d4fec6c) SHA1(3541b5c6405ad5742a3121dfd6acb227933de25a) ) /* MO flip control */
	ROM_LOAD( "74s287-136037-103.4r", 0x400, 0x100, CRC(6c5ccf08) SHA1(ff5dbadd85aa2e07b383a302fa399e875db8f84f) ) /* MO position/size */
ROM_END

GAME( 1987, gaunt2s,  gaunt2,   gauntlet, gauntlet, gauntlet_state, gauntlet2, ROT0, "Todd Bordelon", "Gauntlet II Speed Hack", GAME_SUPPORTS_SAVE ) // http://www.ionpool.net/arcade/gauntlet/hacks.html
