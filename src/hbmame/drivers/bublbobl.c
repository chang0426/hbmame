#include "../mame/drivers/bublbobl.c"

ROM_START( bb2bmh )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "a78-06.51", 	  0x00000, 0x08000, CRC(32c8305b) SHA1(6bf69b3edfbefd33cd670a762b4bf0b39629a220) )
	ROM_LOAD( "bb2bmh-05.52",    0x10000, 0x10000, CRC(d286f2e9) SHA1(ac293aa5bb3973738c7a48ce78c523154d650ded) )

	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "bb2bmh-08.37",    0x0000, 0x08000, CRC(ebce6c5c) SHA1(bd99a67a044763567c443b174115aae89957a60c) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46", 	  0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x0800, "mcu", 0 )
	ROM_LOAD( "68705.bin",    0x0000, 0x0800, CRC(78caa635) SHA1(a756e45b25b007843ba4f2204cad6081cf7260e9) ) /* from a pirate board */

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END

ROM_START( bbhackv1 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "a78-06.51", 	  0x00000, 0x08000, CRC(32c8305b) SHA1(6bf69b3edfbefd33cd670a762b4bf0b39629a220) )
	ROM_LOAD( "bbhackv1-05.52",  0x10000, 0x10000, CRC(8da82422) SHA1(385ccd427b101255bc865af0802672b4d8432339) )
	
	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "bbhackv1-08.37",  0x0000, 0x08000, CRC(419caf60) SHA1(95d680c2be15e813081d3f78f17c5d97eda8b60b) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46", 	  0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x0800, "mcu", 0 )
	ROM_LOAD( "68705.bin", 	  0x0000, 0x0800, CRC(78caa635) SHA1(a756e45b25b007843ba4f2204cad6081cf7260e9) ) /* from a pirate board */

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END

ROM_START( bbredux )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bb3",          0x00000, 0x8000, CRC(d51de9f3) SHA1(dc6bc93692145563a88c146eeb1d0361e25af840) )
	/* ROMs banked at 8000-bfff */
	ROM_LOAD( "bb5",          0x10000, 0x8000, CRC(d29d3444) SHA1(3db694a6ba2ba2ed85d31c2bc4c7c94911b99b85) )
	ROM_LOAD( "bb4",          0x18000, 0x8000, CRC(bd5f6206) SHA1(106d5e174f6fad8ee96fdda19f5367eee18cebe8) )

	ROM_REGION( 0x10000, "slave", 0 )   /* 64k for the second CPU */
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the third CPU */
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	/* 0x30000-0x3ffff empty */
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )
	/* 0x70000-0x7ffff empty */

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )    /* video timing */

	ROM_REGION( 0x0600, "plds", 0 )
	ROM_LOAD( "pal16r4.u36", 0x0000, 0x0104, CRC(22fe26ac) SHA1(bbbfcbe6faded4af7ceec57b800297c054a997da) )
	ROM_LOAD( "pal16l8.u38", 0x0200, 0x0104, CRC(c02d9663) SHA1(5d23cfd96f072981fd5fcf0dd7e98459da58b662) )
	ROM_LOAD( "pal16l8.u4",  0x0400, 0x0104, CRC(077d20a8) SHA1(8e568ffd6f66c3dd61708dd0f3be9c2ed488ae4b) )
ROM_END

//Press P1+P2 while playing, to advance
ROM_START( bbredux1 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bb3",          0x00000, 0x8000, CRC(b802046d) SHA1(93dba2507c67f3f61eca80908a7a4409d2cd1b75) )
	/* ROMs banked at 8000-bfff */
	ROM_LOAD( "bb5",          0x10000, 0x8000, CRC(d29d3444) SHA1(3db694a6ba2ba2ed85d31c2bc4c7c94911b99b85) )
	ROM_LOAD( "bb4",          0x18000, 0x8000, CRC(3cbb8b41) SHA1(78c6c26e585699b34e47a69dfd63dd2feec0e483) )

	ROM_REGION( 0x10000, "slave", 0 )   /* 64k for the second CPU */
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the third CPU */
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	/* 0x30000-0x3ffff empty */
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )
	/* 0x70000-0x7ffff empty */

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )    /* video timing */

	ROM_REGION( 0x0600, "plds", 0 )
	ROM_LOAD( "pal16r4.u36", 0x0000, 0x0104, CRC(22fe26ac) SHA1(bbbfcbe6faded4af7ceec57b800297c054a997da) )
	ROM_LOAD( "pal16l8.u38", 0x0200, 0x0104, CRC(c02d9663) SHA1(5d23cfd96f072981fd5fcf0dd7e98459da58b662) )
	ROM_LOAD( "pal16l8.u4",  0x0400, 0x0104, CRC(077d20a8) SHA1(8e568ffd6f66c3dd61708dd0f3be9c2ed488ae4b) )
ROM_END

// When you die for the last time, it momentarily says says press P1. Do so, to continue.
ROM_START( bbredux2 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bb3",          0x00000, 0x8000, CRC(198dc44e) SHA1(de9538b47703c468f85ba318deb8aa0b65174a26) )
	/* ROMs banked at 8000-bfff */
	ROM_LOAD( "bb5",          0x10000, 0x8000, CRC(d29d3444) SHA1(3db694a6ba2ba2ed85d31c2bc4c7c94911b99b85) )
	ROM_LOAD( "bb4",          0x18000, 0x8000, CRC(be9fb0d9) SHA1(411be7f4e243315e6b280b48219f6e5f48281510) )

	ROM_REGION( 0x10000, "slave", 0 )   /* 64k for the second CPU */
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the third CPU */
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	/* 0x30000-0x3ffff empty */
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )
	/* 0x70000-0x7ffff empty */

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )    /* video timing */

	ROM_REGION( 0x0600, "plds", 0 )
	ROM_LOAD( "pal16r4.u36", 0x0000, 0x0104, CRC(22fe26ac) SHA1(bbbfcbe6faded4af7ceec57b800297c054a997da) )
	ROM_LOAD( "pal16l8.u38", 0x0200, 0x0104, CRC(c02d9663) SHA1(5d23cfd96f072981fd5fcf0dd7e98459da58b662) )
	ROM_LOAD( "pal16l8.u4",  0x0400, 0x0104, CRC(077d20a8) SHA1(8e568ffd6f66c3dd61708dd0f3be9c2ed488ae4b) )
ROM_END

// High score save is not working as yet
ROM_START( bbredux3 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bb3",          0x00000, 0x8000, CRC(959cafca) SHA1(9c541e45326d27f4d25a1fd9d66f234ce7f969c9) )
	/* ROMs banked at 8000-bfff */
	ROM_LOAD( "bb5",          0x10000, 0x8000, CRC(d29d3444) SHA1(3db694a6ba2ba2ed85d31c2bc4c7c94911b99b85) )
	ROM_LOAD( "bb4",          0x18000, 0x8000, CRC(1a2b2bfc) SHA1(60495234d5ae33ded5c082f467b66947cf05d134) )

	ROM_REGION( 0x10000, "slave", 0 )   /* 64k for the second CPU */
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the third CPU */
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	/* 0x30000-0x3ffff empty */
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )
	/* 0x70000-0x7ffff empty */

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )    /* video timing */

	ROM_REGION( 0x0600, "plds", 0 )
	ROM_LOAD( "pal16r4.u36", 0x0000, 0x0104, CRC(22fe26ac) SHA1(bbbfcbe6faded4af7ceec57b800297c054a997da) )
	ROM_LOAD( "pal16l8.u38", 0x0200, 0x0104, CRC(c02d9663) SHA1(5d23cfd96f072981fd5fcf0dd7e98459da58b662) )
	ROM_LOAD( "pal16l8.u4",  0x0400, 0x0104, CRC(077d20a8) SHA1(8e568ffd6f66c3dd61708dd0f3be9c2ed488ae4b) )
ROM_END

ROM_START( sboblboblh )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bb3.u28",      0x00000, 0x08000, CRC(c23cd704) SHA1(a389ecc8d55d1b0c915fd3814d93338b9e402701) )
	/* ROMs banked at 8000-bfff */
	ROM_LOAD( "bb5",          0x10000, 0x08000, CRC(13118eb1) SHA1(5a5da40c2cc82420f70bc58ffa32de1088c6c82f) )
	ROM_LOAD( "bbb-4.rom",    0x18000, 0x08000, CRC(94c75591) SHA1(7698bc4b7d20e554a73a489cd3a15ae61b350e37) )
	/* 20000-2ffff empty */

	ROM_REGION( 0x10000, "slave", 0 )   /* 64k for the second CPU */
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )    /* 64k for the third CPU */
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	/* 0x30000-0x3ffff empty */
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )
	/* 0x70000-0x7ffff empty */

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )    /* video timing */
ROM_END

ROM_START( bublbobf )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bublbobf-06.51",    0x00000, 0x08000, CRC(9ced3d8f) SHA1(d445f218fca822e7083a9347abd4a4e049b6555b) )
	ROM_LOAD( "bublbobf-05.52",    0x10000, 0x10000, CRC(56197d88) SHA1(b1b750df33835df012b2550585edcd6ea58db186) )

	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "a78-08.37",    0x0000, 0x08000, CRC(ae11a07b) SHA1(af7a335c8da637103103cc274e077f123908ebb7) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46",    0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "a78-01.17",    0xf000, 0x1000, CRC(b1bfb53d) SHA1(31b8f31acd3aa394acd80db362774749842e1285) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "a78-09.12",    0x00000, 0x8000, CRC(20358c22) SHA1(2297af6c53d5807bf90a8e081075b8c72a994fc5) )    /* 1st plane */
	ROM_LOAD( "a78-10.13",    0x08000, 0x8000, CRC(930168a9) SHA1(fd358c3c3b424bca285f67a1589eb98a345ff670) )
	ROM_LOAD( "a78-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "a78-12.15",    0x18000, 0x8000, CRC(d045549b) SHA1(0c12077d3ddc2ce6aa45a0224ad5540f3f218446) )
	ROM_LOAD( "a78-13.16",    0x20000, 0x8000, CRC(d0af35c5) SHA1(c5a89f4d73acc0db86654540b3abfd77b3757db5) )
	ROM_LOAD( "a78-14.17",    0x28000, 0x8000, CRC(7b5369a8) SHA1(1307b26d80e6f36ebe6c442bebec41d20066eaf9) )
	ROM_LOAD( "a78-15.30",    0x40000, 0x8000, CRC(6b61a413) SHA1(44eddf12fb46fceca2addbe6da929aaea7636b13) )    /* 2nd plane */
	ROM_LOAD( "a78-16.31",    0x48000, 0x8000, CRC(b5492d97) SHA1(d5b045e3ebaa44809757a4220cefb3c6815470da) )
	ROM_LOAD( "a78-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "a78-18.33",    0x58000, 0x8000, CRC(9f243b68) SHA1(32dce8d311a4be003693182a999e4053baa6bb0a) )
	ROM_LOAD( "a78-19.34",    0x60000, 0x8000, CRC(66e9438c) SHA1(b94e62b6fbe7f4e08086d0365afc5cff6e0ccafd) )
	ROM_LOAD( "a78-20.35",    0x68000, 0x8000, CRC(9ef863ad) SHA1(29f91b5a3765e4d6e6c3382db1d8d8297b6e56c8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",    0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END

ROM_START( bublcave )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bublcave-06.51",    0x00000, 0x08000, CRC(e8b9af5e) SHA1(dec44e47634a402df212806e84e3a810f8442776) )
	ROM_LOAD( "bublcave-05.52",    0x10000, 0x10000, CRC(cfe14cb8) SHA1(17d463c755f630ae9d05943515fa4828972bd7b0) )

	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "bublcave-08.37",    0x0000, 0x08000, CRC(a9384086) SHA1(26e686671d6d3ba3759716bf46e7f951bbb8a291) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46",         0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "a78-01.17",         0xf000, 0x1000, CRC(b1bfb53d) SHA1(31b8f31acd3aa394acd80db362774749842e1285) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "bublcave-09.12",    0x00000, 0x8000, CRC(b90b7eef) SHA1(de72e4635843ad76248aa3b4aa8f8a0bfd53879e) )    /* 1st plane */
	ROM_LOAD( "bublcave-10.13",    0x08000, 0x8000, CRC(4fb22f05) SHA1(880104e86dbd00ae657cbc768722427503b6a59f) )
	ROM_LOAD( "bublcave-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "bublcave-12.15",    0x18000, 0x8000, CRC(e49eb49e) SHA1(2e05dc8833e10bef1a317d238c39fb9f362e9997) )
	ROM_LOAD( "bublcave-13.16",    0x20000, 0x8000, CRC(61919734) SHA1(2c07e29f3dcc972d5eb47679ad81a0d7656b0cb2) )
	ROM_LOAD( "bublcave-14.17",    0x28000, 0x8000, CRC(7e3a13bd) SHA1(bd4dba799340fa599f11cc68e03efe70ba6ba99b) )
	ROM_LOAD( "bublcave-15.30",    0x40000, 0x8000, CRC(c253c73a) SHA1(3e187f6b9ca769772990068abe7b309417147d39) )    /* 2nd plane */
	ROM_LOAD( "bublcave-16.31",    0x48000, 0x8000, CRC(e66c92ee) SHA1(12ea193c54121d08ad110c94cc075e29fef3ff85) )
	ROM_LOAD( "bublcave-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "bublcave-18.33",    0x58000, 0x8000, CRC(47ee2544) SHA1(c6946e824043a312ed437e548a64ef599effbd42) )
	ROM_LOAD( "bublcave-19.34",    0x60000, 0x8000, CRC(1ceeb1fa) SHA1(eb29ff896d149f7ab4cf38a338df39df14ccc20c) )
	ROM_LOAD( "bublcave-20.35",    0x68000, 0x8000, CRC(64322e24) SHA1(acff8a9fcaf74f198653080759898d15cccf04e8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",         0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END

ROM_START( bublcave11 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bublcave10-06.51",  0x00000, 0x08000, CRC(185cc219) SHA1(dfb312f144fb01c07581cb8ea55ab0dc92ccd5b2) )
	ROM_LOAD( "bublcave11-05.52",  0x10000, 0x10000, CRC(b6b02df3) SHA1(542589544216a54f84c213b161d7145934875d2b) )

	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "bublcave11-08.37",  0x0000, 0x08000, CRC(c5d14e62) SHA1(b32b1ca76b54755a69a7a346d01545f2699e1363) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46",         0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "a78-01.17",         0xf000, 0x1000, CRC(b1bfb53d) SHA1(31b8f31acd3aa394acd80db362774749842e1285) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "bublcave-09.12",    0x00000, 0x8000, CRC(b90b7eef) SHA1(de72e4635843ad76248aa3b4aa8f8a0bfd53879e) )    /* 1st plane */
	ROM_LOAD( "bublcave-10.13",    0x08000, 0x8000, CRC(4fb22f05) SHA1(880104e86dbd00ae657cbc768722427503b6a59f) )
	ROM_LOAD( "bublcave-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "bublcave-12.15",    0x18000, 0x8000, CRC(e49eb49e) SHA1(2e05dc8833e10bef1a317d238c39fb9f362e9997) )
	ROM_LOAD( "bublcave-13.16",    0x20000, 0x8000, CRC(61919734) SHA1(2c07e29f3dcc972d5eb47679ad81a0d7656b0cb2) )
	ROM_LOAD( "bublcave-14.17",    0x28000, 0x8000, CRC(7e3a13bd) SHA1(bd4dba799340fa599f11cc68e03efe70ba6ba99b) )
	ROM_LOAD( "bublcave-15.30",    0x40000, 0x8000, CRC(c253c73a) SHA1(3e187f6b9ca769772990068abe7b309417147d39) )    /* 2nd plane */
	ROM_LOAD( "bublcave-16.31",    0x48000, 0x8000, CRC(e66c92ee) SHA1(12ea193c54121d08ad110c94cc075e29fef3ff85) )
	ROM_LOAD( "bublcave-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "bublcave-18.33",    0x58000, 0x8000, CRC(47ee2544) SHA1(c6946e824043a312ed437e548a64ef599effbd42) )
	ROM_LOAD( "bublcave-19.34",    0x60000, 0x8000, CRC(1ceeb1fa) SHA1(eb29ff896d149f7ab4cf38a338df39df14ccc20c) )
	ROM_LOAD( "bublcave-20.35",    0x68000, 0x8000, CRC(64322e24) SHA1(acff8a9fcaf74f198653080759898d15cccf04e8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",         0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END

ROM_START( bublcave10 )
	ROM_REGION( 0x30000, "maincpu", 0 )
	ROM_LOAD( "bublcave10-06.51",  0x00000, 0x08000, CRC(185cc219) SHA1(dfb312f144fb01c07581cb8ea55ab0dc92ccd5b2) )
	ROM_LOAD( "bublcave10-05.52",  0x10000, 0x10000, CRC(381cdde7) SHA1(0c9de44d7dbad754e873af8ddb5a2736f5ec2096) )

	ROM_REGION( 0x10000, "slave", 0 )
	ROM_LOAD( "bublcave10-08.37",  0x0000, 0x08000, CRC(026a68e1) SHA1(9e54310a9f1f5187ea6eb49d9189865b44708a7e) )

	ROM_REGION( 0x10000, "audiocpu", 0 )
	ROM_LOAD( "a78-07.46",         0x0000, 0x08000, CRC(4f9a26e8) SHA1(3105b34b88a7134493c2b3f584729f8b0407a011) )

	ROM_REGION( 0x10000, "mcu", 0 )
	ROM_LOAD( "a78-01.17",         0xf000, 0x1000, CRC(b1bfb53d) SHA1(31b8f31acd3aa394acd80db362774749842e1285) )

	ROM_REGION( 0x80000, "gfx1", ROMREGION_INVERT )
	ROM_LOAD( "bublcave-09.12",    0x00000, 0x8000, CRC(b90b7eef) SHA1(de72e4635843ad76248aa3b4aa8f8a0bfd53879e) )    /* 1st plane */
	ROM_LOAD( "bublcave-10.13",    0x08000, 0x8000, CRC(4fb22f05) SHA1(880104e86dbd00ae657cbc768722427503b6a59f) )
	ROM_LOAD( "bublcave-11.14",    0x10000, 0x8000, CRC(9773e512) SHA1(33c1687ee575d66bf0e98add45d06da827813765) )
	ROM_LOAD( "bublcave-12.15",    0x18000, 0x8000, CRC(e49eb49e) SHA1(2e05dc8833e10bef1a317d238c39fb9f362e9997) )
	ROM_LOAD( "bublcave-13.16",    0x20000, 0x8000, CRC(61919734) SHA1(2c07e29f3dcc972d5eb47679ad81a0d7656b0cb2) )
	ROM_LOAD( "bublcave-14.17",    0x28000, 0x8000, CRC(7e3a13bd) SHA1(bd4dba799340fa599f11cc68e03efe70ba6ba99b) )
	ROM_LOAD( "bublcave-15.30",    0x40000, 0x8000, CRC(c253c73a) SHA1(3e187f6b9ca769772990068abe7b309417147d39) )    /* 2nd plane */
	ROM_LOAD( "bublcave-16.31",    0x48000, 0x8000, CRC(e66c92ee) SHA1(12ea193c54121d08ad110c94cc075e29fef3ff85) )
	ROM_LOAD( "bublcave-17.32",    0x50000, 0x8000, CRC(d69762d5) SHA1(3326fef4e0bd86681a3047dc11886bb171ecb609) )
	ROM_LOAD( "bublcave-18.33",    0x58000, 0x8000, CRC(47ee2544) SHA1(c6946e824043a312ed437e548a64ef599effbd42) )
	ROM_LOAD( "bublcave-19.34",    0x60000, 0x8000, CRC(1ceeb1fa) SHA1(eb29ff896d149f7ab4cf38a338df39df14ccc20c) )
	ROM_LOAD( "bublcave-20.35",    0x68000, 0x8000, CRC(64322e24) SHA1(acff8a9fcaf74f198653080759898d15cccf04e8) )

	ROM_REGION( 0x0100, "proms", 0 )
	ROM_LOAD( "a71-25.41",         0x0000, 0x0100, CRC(2d0f8545) SHA1(089c31e2f614145ef2743164f7b52ae35bc06808) )	/* video timing */
ROM_END


GAME( 2000, bb2bmh,     bublbobl, bub68705, bublbobl, bublbobl_state, bublbobl, ROT0, "Taito", "Bubble Bobble (Memories Hack)", GAME_SUPPORTS_SAVE )
GAME( 2000, bbhackv1,   bublbobl, bub68705, bublbobl, bublbobl_state, bublbobl, ROT0, "[Taito]", "Bubble Bobble (Level Hack)", GAME_SUPPORTS_SAVE )
GAME( 2013, bbredux,    bublbobl, boblbobl, boblbobl, bublbobl_state, bublbobl, ROT0, "Punji", "Bobble Bobble Redux", GAME_SUPPORTS_SAVE )
GAME( 2013, bbredux1,   bublbobl, boblbobl, boblbobl, bublbobl_state, bublbobl, ROT0, "Punji", "Bobble Bobble Redux (Level Skip)", GAME_SUPPORTS_SAVE )
GAME( 2013, bbredux2,   bublbobl, boblbobl, boblbobl, bublbobl_state, bublbobl, ROT0, "Punji", "Bobble Bobble Redux (Game Continue)", GAME_SUPPORTS_SAVE )
GAME( 2013, bbredux3,   bublbobl, boblbobl, boblbobl, bublbobl_state, bublbobl, ROT0, "Punji", "Bobble Bobble Redux (High Score)", GAME_SUPPORTS_SAVE )
GAME( 19??, sboblboblh, bublbobl, boblbobl, boblbobl, bublbobl_state, bublbobl, ROT0, "hack", "Super Bobble Bobble (Level Select)", GAME_SUPPORTS_SAVE )
GAME( 2007, bublbobf,   bublbobl, bublbobl, bublbobl, bublbobl_state, bublbobl, ROT0, "Arkatrad", "Bubble Bobble (French)", GAME_SUPPORTS_SAVE )
GAME( 2013, bublcave,   bublbobl, bublbobl, bublbobl, bublbobl_state, bublbobl, ROT0, "Bisboch and Aladar", "Bubble Bobble: Lost Cave V1.2", GAME_SUPPORTS_SAVE )
GAME( 2012, bublcave11, bublbobl, bublbobl, bublbobl, bublbobl_state, bublbobl, ROT0, "Bisboch and Aladar", "Bubble Bobble: Lost Cave V1.1", GAME_SUPPORTS_SAVE )
GAME( 2012, bublcave10, bublbobl, bublbobl, bublbobl, bublbobl_state, bublbobl, ROT0, "Bisboch and Aladar", "Bubble Bobble: Lost Cave V1.0", GAME_SUPPORTS_SAVE )
