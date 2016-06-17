// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/taito_f3.cpp"

ROM_START( arkretrh )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("e36-11", 0x000000, 0x040000, CRC(b50cfb92) SHA1(dac69fc9ef03315b11bb94d19e3dfdc8867b08ed) )
	ROM_LOAD32_BYTE("e36-10", 0x000001, 0x040000, CRC(c940dba1) SHA1(ec87c9e4250f8b2f15094681a4783bca8c68f576) )
	ROM_LOAD32_BYTE("e36-09", 0x000002, 0x040000, CRC(f16985e0) SHA1(a74cfee8f958e7a32354d4353eeb199a7fb1ce64) )
	ROM_LOAD32_BYTE("e36-wrd", 0x000003, 0x040000, CRC(4467ff37) SHA1(509a0d516def02d86d81b9868de0d9593539e65c) )

	ROM_REGION(0x180000, "taito_en:audiocpu", 0)	/* Sound CPU */
	ROM_LOAD16_BYTE("e36-12", 0x100000, 0x40000, CRC(3bae39be) SHA1(777142ecc24799b934ed51ac4cd8700bb6da7e3c) )
	ROM_LOAD16_BYTE("e36-13", 0x100001, 0x40000, CRC(94448e82) SHA1(d7766490318623be770545918391c5e6144dd619) )

	ROM_REGION(0x100000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e36-03", 0x000000, 0x040000, CRC(1ea8558b) SHA1(b8ea4d6e1fb551b3c47f336a5e60ec33f7be525f) )
	ROM_LOAD16_BYTE("e36-02", 0x000001, 0x040000, CRC(694eda31) SHA1(1a6f85057395052571491f85c633d5632ab64865) )
	ROM_LOAD       ("e36-01", 0x0c0000, 0x040000, CRC(54b9b2cd) SHA1(55ae964ea1d2cc40a6578c5339754a270096f01f) )
	ROM_FILL       (          0x080000, 0x040000, 0 )

	ROM_REGION(0x200000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("e36-07", 0x000000, 0x080000, CRC(266bf1c1) SHA1(489549478d7016400af2e643d4b98bf605237d34) )
	ROM_LOAD16_BYTE("e36-06", 0x000001, 0x080000, CRC(110ab729) SHA1(0ccc0a5abbcfd79a069daf5162cd344a5fb225d5) )
	ROM_LOAD       ("e36-05", 0x180000, 0x080000, CRC(db18bce2) SHA1(b6653facc7f5c624f5710a51f2b2abfe640177e2) )
	ROM_FILL       (          0x100000, 0x080000, 0 )

	ROM_REGION16_BE(0x400000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 1 populated
	ROM_LOAD16_BYTE("e36-04", 0x000000, 0x200000, CRC(2250959b) SHA1(06943f1b72bdf325485356a01278d88aeae93d87) )	// C8 C9 CA CB
ROM_END

ROM_START( cleopath )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("e28-10.bin", 0x000000, 0x80000, CRC(013fbc39) SHA1(d36ac44609b88e1da35c98dda381042e0112ea00) )
	ROM_LOAD32_BYTE("e28-09.bin", 0x000001, 0x80000, CRC(1c48a1f9) SHA1(791d321c03073cdd0269b970f926897446d2a6fb) )
	ROM_LOAD32_BYTE("e28-08.bin", 0x000002, 0x80000, CRC(7564f199) SHA1(ec4b19edb0660ad478f6c0ec27d701368696a2e4) )
	ROM_LOAD32_BYTE("e28-wrd.bin", 0x000003, 0x80000, CRC(544dd2e9) SHA1(11ad1ce4202937108f23c44de2244da570452ce1) )

	ROM_REGION(0x200000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e28-02.bin", 0x000000, 0x080000, CRC(b20d47cb) SHA1(6888e5564688840fed1c123ab38467066cd59c7f) )
	ROM_LOAD16_BYTE("e28-01.bin", 0x000001, 0x080000, CRC(4440e659) SHA1(71dece81bac8d638473c6531fed5c32798096af9) )
	ROM_FILL       (              0x100000, 0x100000, 0 )

	ROM_REGION(0x400000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("e28-06.bin", 0x000000, 0x100000, CRC(21d0c454) SHA1(f4c815984b19321cfab303fa6f21d9cad35b09f2) )
	ROM_LOAD16_BYTE("e28-05.bin", 0x000001, 0x100000, CRC(2870dbbc) SHA1(4e412b90cbd9a05956cde3d8cff615ebadca9db6) )
	ROM_LOAD       ("e28-04.bin", 0x300000, 0x100000, CRC(57aef029) SHA1(5c07209015d4749d1ffb3e9c1a890e6cfeec8cb0) )
	ROM_FILL       (              0x200000, 0x100000, 0 )

	ROM_REGION(0x140000, "taito_en:audiocpu", 0)	/* Sound CPU */
	ROM_LOAD16_BYTE("e28-11.bin", 0x100000, 0x20000, CRC(01a06950) SHA1(94d22cd839f9027e9d45264c366e0cb5d698e0b6) )
	ROM_LOAD16_BYTE("e28-12.bin", 0x100001, 0x20000, CRC(dc19260f) SHA1(fa0ca03a236326652e4f9898d07cd837c1507a9d) )

	ROM_REGION16_BE(0x400000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 1 populated
	ROM_LOAD16_BYTE("e28-03.bin", 0x000000, 0x200000, CRC(15c7989d) SHA1(7cc63d93e5c1f9f52f889e973bbefd5e6f7ce807) )	// C8 C9 CA CB
ROM_END

ROM_START( driusgxh )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("dge_mpr3.bin", 0x000000, 0x80000, CRC(1c1e24a7) SHA1(eafde331c3be5be55d0d838a84017f357ff92634) )
	ROM_LOAD32_BYTE("dge_mpr2.bin", 0x000001, 0x80000, CRC(7be23e23) SHA1(4764355f51e207f4538dd753aea59bf2689835de) )
	ROM_LOAD32_BYTE("dge_mpr1.bin", 0x000002, 0x80000, CRC(bc030f6f) SHA1(841396911d26ddfae0c9863431e02e0b5e762ac6) )
	ROM_LOAD32_BYTE("dge_wrd.bin",  0x000003, 0x80000, CRC(2bb37270) SHA1(98bc07894e92ca9cce34fc7390f40d3357783e3f) )

	ROM_REGION(0x800000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("d87-03.bin", 0x000000, 0x200000, CRC(4be1666e) SHA1(35ba7bcf29ec7a8f8b6944ee3544693d4df1bfc2) )
	ROM_LOAD16_BYTE("d87-04.bin", 0x000001, 0x200000, CRC(2616002c) SHA1(003f98b740a697274385b8da03c78f3c6f7b5e89) )
	ROM_LOAD       ("d87-05.bin", 0x600000, 0x200000, CRC(4e5891a9) SHA1(fd08d848079841c9237fa359a850980fd00114d8) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x800000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("d87-06.bin", 0x000000, 0x200000, CRC(3b97a07c) SHA1(72cdeffedeab0c1bd0e47f03172085390a2be393) )
	ROM_LOAD16_BYTE("d87-17.bin", 0x000001, 0x200000, CRC(e601d63e) SHA1(256a6aeb5633fe1db407fad567169a9d0c911219) )
	ROM_LOAD       ("d87-08.bin", 0x600000, 0x200000, CRC(76d23602) SHA1(ca53ea6641182c44a4038bbeaa5effb1687f1980) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x180000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("d87-13.bin", 0x100000, 0x40000, CRC(15b1fff4) SHA1(28692b731ae98a47c2c5e11a8a71b61a813d9a64) )
	ROM_LOAD16_BYTE("d87-14.bin", 0x100001, 0x40000, CRC(eecda29a) SHA1(6eb238e47bc7bf635ffbdbb25fb06a37db980ef8) )

	ROM_REGION16_BE(0x800000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 2 populated
	ROM_LOAD16_BYTE("d87-01.bin", 0x000000, 0x200000, CRC(3848a110) SHA1(802e91695a526f665c7fd261f0a7639a0b883c9e) )	// C9 CA CB CC
	ROM_LOAD16_BYTE("d87-02.bin", 0x400000, 0x200000, CRC(9250abae) SHA1(07cae8edbc3cca0a95022d9b40a5c18a55350b67) )	// CD CE CF D0
ROM_END

ROM_START( f3demo )
	ROM_REGION(0x200000, "maincpu", ROMREGION_ERASE00) /* 68020 code */
	ROM_LOAD("f3demo.bin", 0, 0x194c, CRC(08587aea) SHA1(4850d170b935fd4b6726c03693eb25e5ac3b6198) )
	ROM_FILL(0x043A, 1, 0x4E)
	ROM_FILL(0x043B, 1, 0xB8)
	ROM_FILL(0x043C, 1, 0x19)
	ROM_FILL(0x043D, 1, 0x4C)
	ROM_FILL(0x194C, 1, 0x41)
	ROM_FILL(0x194D, 1, 0xF9)
	ROM_FILL(0x194F, 1, 0x66)
	ROM_FILL(0x1951, 1, 0x18)
	ROM_FILL(0x1952, 1, 0x30)
	ROM_FILL(0x1953, 1, 0x3C)
	ROM_FILL(0x1955, 1, 0x9E)
	ROM_FILL(0x1956, 1, 0x31)
	ROM_FILL(0x1957, 1, 0x40)
	ROM_FILL(0x195A, 1, 0x30)
	ROM_FILL(0x195B, 1, 0x3C)
	ROM_FILL(0x195D, 1, 0xF1)
	ROM_FILL(0x195E, 1, 0x31)
	ROM_FILL(0x195F, 1, 0x40)
	ROM_FILL(0x1961, 1, 0x02)
	ROM_FILL(0x1962, 1, 0x60)
	ROM_FILL(0x1963, 1, 0xFE)

	ROM_REGION(0x800000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("d87-03.bin", 0x000000, 0x200000, CRC(4be1666e) SHA1(35ba7bcf29ec7a8f8b6944ee3544693d4df1bfc2) )
	ROM_LOAD16_BYTE("d87-04.bin", 0x000001, 0x200000, CRC(2616002c) SHA1(003f98b740a697274385b8da03c78f3c6f7b5e89) )
	ROM_LOAD       ("d87-05.bin", 0x600000, 0x200000, CRC(4e5891a9) SHA1(fd08d848079841c9237fa359a850980fd00114d8) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x800000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("d87-06.bin", 0x000000, 0x200000, CRC(3b97a07c) SHA1(72cdeffedeab0c1bd0e47f03172085390a2be393) )
	ROM_LOAD16_BYTE("d87-17.bin", 0x000001, 0x200000, CRC(e601d63e) SHA1(256a6aeb5633fe1db407fad567169a9d0c911219) )
	ROM_LOAD       ("d87-08.bin", 0x600000, 0x200000, CRC(76d23602) SHA1(ca53ea6641182c44a4038bbeaa5effb1687f1980) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x180000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("d87-13.bin", 0x100000, 0x40000, CRC(15b1fff4) SHA1(28692b731ae98a47c2c5e11a8a71b61a813d9a64) )
	ROM_LOAD16_BYTE("d87-14.bin", 0x100001, 0x40000, CRC(eecda29a) SHA1(6eb238e47bc7bf635ffbdbb25fb06a37db980ef8) )

	ROM_REGION16_BE(0x800000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 2 populated
	ROM_LOAD16_BYTE("d87-01.bin", 0x000000, 0x200000, CRC(3848a110) SHA1(802e91695a526f665c7fd261f0a7639a0b883c9e) )	// C9 CA CB CC
	ROM_LOAD16_BYTE("d87-02.bin", 0x400000, 0x200000, CRC(9250abae) SHA1(07cae8edbc3cca0a95022d9b40a5c18a55350b67) )	// CD CE CF D0
ROM_END

ROM_START( gekiridh )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("e11-12.bin", 0x000000, 0x40000, CRC(6a7aaacf) SHA1(a8114c84e76c75c908a61d985d96aa4eb9a0ac5a) )
	ROM_LOAD32_BYTE("e11-11.bin", 0x000001, 0x40000, CRC(2284a08e) SHA1(3dcb91be0d3491ad5e77efd30bacd506dad0f848) )
	ROM_LOAD32_BYTE("e11-10.bin", 0x000002, 0x40000, CRC(8795e6ba) SHA1(9128c29fdce3276f55aad47451e4a507470c8b9f) )
	ROM_LOAD32_BYTE("e11-wrd.bin", 0x000003, 0x40000, CRC(5aef1fd8) SHA1(a94884e39172e664759bff53a6dd2f93422d3299) )

	ROM_REGION(0x800000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e11-03.bin", 0x000000, 0x200000, CRC(f73877c5) SHA1(1f6b7c0b8a0aaab3e5427d21de7fad3d3cbf737a) )
  	ROM_LOAD16_BYTE("e11-02.bin", 0x000001, 0x200000, CRC(5722a83b) SHA1(823c20a33016a5506ca5415ec615c3d2546ca9ab) )
	ROM_LOAD       ("e11-01.bin", 0x600000, 0x200000, CRC(c2cd1069) SHA1(9744dd3d8a6d9200cea4429dafce5620b60e2960) )
 	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x800000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("e11-08.bin", 0x000000, 0x200000, CRC(907f69d3) SHA1(0899ed58edcae22144625c349c9d2fe4d46d11e3) )
	ROM_LOAD16_BYTE("e11-07.bin", 0x000001, 0x200000, CRC(ef018607) SHA1(61b602b13754c3be21caf76acbfc10c87518ba47) )
	ROM_LOAD       ("e11-06.bin", 0x600000, 0x200000, CRC(200ce305) SHA1(c80a0b96510913a6411e6763fb72bf413fb792da) )
 	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x140000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("e11-13.bin", 0x100000, 0x20000, CRC(51a11ff7) SHA1(c03042489d71423667f25856d15aa6a363ea6c92) )
	ROM_LOAD16_BYTE("e11-14.bin", 0x100001, 0x20000, CRC(dce2ba91) SHA1(00bc353c7747a7954365b587d7bc759ee5dc09c2) )

	ROM_REGION16_BE(0x800000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 2 populated
	ROM_LOAD16_BYTE("e11-04.bin", 0x000000, 0x200000, CRC(e0ff4fb1) SHA1(81e186e3a692af1da316b8085a729c4f103d9a52) )	// C8 C9 CA CB
	ROM_LOAD16_BYTE("e11-05.bin", 0x400000, 0x200000, CRC(a4d08cf1) SHA1(ae2cabef7b7bcb8a788988c73d7af6fa4bb2c444) )	// CC CD -std-
ROM_END

ROM_START( gekiridoc )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
	ROM_LOAD32_BYTE("e11-12c.bin", 0x000000, 0x40000, CRC(448308ce) SHA1(22eac25158bd3a0349aa4f1f041473b93030ee43) )
	ROM_LOAD32_BYTE("e11-11c.bin", 0x000001, 0x40000, CRC(8ae457c4) SHA1(f1d74d99c916df90a74be0ff80b05b0f31284306) )
	ROM_LOAD32_BYTE("e11-10c.bin", 0x000002, 0x40000, CRC(b1ff4529) SHA1(9e8366d9d90ad4155aab3828523daff09e3d400d) )
	ROM_LOAD32_BYTE("e11-09c.bin", 0x000003, 0x40000, CRC(24d884ff) SHA1(35ddb21608c781a0674a4244c8e5c0aa6dc220eb) )

	ROM_REGION(0x800000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e11-03c.bin", 0x000000, 0x200000, CRC(2b0dab58) SHA1(7c70a2104fbbfde32fa006bfafe30c3d9708cb10) )
	ROM_LOAD16_BYTE("e11-02c.bin", 0x000001, 0x200000, CRC(a2c4fa4f) SHA1(2ad73ce8431f1199dd32df83352dc4f85345529f) )
	ROM_LOAD       ("e11-01c.bin", 0x600000, 0x200000, CRC(e19874b3) SHA1(a8d6806133977a7decefafff5d7b249803add70b) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x800000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("e11-08c.bin", 0x000000, 0x200000, CRC(93884253) SHA1(6d0530db64c84bf7b2ad47e94036ecd8c81418b6) )
	ROM_LOAD16_BYTE("e11-07c.bin", 0x000001, 0x200000, CRC(15ca8ac2) SHA1(33cbcc96e5144e5910c67c99815958d8f004287e) )
	ROM_LOAD       ("e11-06c.bin", 0x600000, 0x200000, CRC(0acc71d3) SHA1(455c70ec8f1087189170160d5683545bbea1fe9a) )
	ROM_FILL       (              0x400000, 0x200000, 0 )

	ROM_REGION(0x140000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("e11-13.bin", 0x100000, 0x20000, CRC(51a11ff7) SHA1(c03042489d71423667f25856d15aa6a363ea6c92) )
	ROM_LOAD16_BYTE("e11-14.bin", 0x100001, 0x20000, CRC(dce2ba91) SHA1(00bc353c7747a7954365b587d7bc759ee5dc09c2) )

	ROM_REGION16_BE(0x800000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 2 populated
	ROM_LOAD16_BYTE("e11-04.ic38", 0x000000, 0x200000, CRC(e0ff4fb1) SHA1(81e186e3a692af1da316b8085a729c4f103d9a52) )	// C8 C9 CA CB
	ROM_LOAD16_BYTE("e11-05.ic41", 0x400000, 0x200000, CRC(a4d08cf1) SHA1(ae2cabef7b7bcb8a788988c73d7af6fa4bb2c444) )	// CC CD -std-
ROM_END

ROM_START( landmakh )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("e61-13.20", 0x000000, 0x80000, CRC(0af756a2) SHA1(2dadac6873f2491ee77703f07f00dde2aa909355) )
	ROM_LOAD32_BYTE("e61-12.19", 0x000001, 0x80000, CRC(636b3df9) SHA1(78a5bf4977bb90d710942188ce5016f3df499feb) )
	ROM_LOAD32_BYTE("e61-11.18", 0x000002, 0x80000, CRC(279a0ee4) SHA1(08380286737b33db76a79b27d0df5faba17dfb96) )
	ROM_LOAD32_BYTE("e61-wrd.17", 0x000003, 0x80000, CRC(34a5939e) SHA1(4fbcdd0b57cbd589b554d1751394df8389293966) )

	ROM_REGION(0x800000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e61-03.12",0x000000, 0x200000, CRC(e8abfc46) SHA1(fbde006f9822af3ed8debec525270d329981ea21) )
	ROM_LOAD16_BYTE("e61-02.08",0x000001, 0x200000, CRC(1dc4a164) SHA1(33b412d9653099aaff8ed5e62d1ba4fc30aa9058) )
	ROM_LOAD       ("e61-01.04",0x600000, 0x200000, CRC(6cdd8311) SHA1(7810a5a81f3b5a730d2088c79b12fffd77659b5b) )
	ROM_FILL       (            0x400000, 0x200000, 0 )

	ROM_REGION(0x800000, "gfx2" , 0) /* Tiles */
	ROM_LOAD16_BYTE("e61-09.47", 0x000000, 0x200000, CRC(6ba29987) SHA1(b63c12523e19da66b3ca07c3548ac81bf57b59a1) )
	ROM_LOAD16_BYTE("e61-08.45", 0x000001, 0x200000, CRC(76c98e14) SHA1(c021c325ab4ae410fa54e2eab61d34318867432b) )
	ROM_LOAD       ("e61-07.43", 0x600000, 0x200000, CRC(4a57965d) SHA1(8e80788e0f47fb242da9af3aa19077dc0ec829b8) )
	ROM_FILL       (             0x400000, 0x200000, 0 )

	ROM_REGION(0x140000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("e61-14.32", 0x100000, 0x20000, CRC(b905f4a7) SHA1(613b954e3e129fd44b4ce64958f16e5636012d6e) )
	ROM_LOAD16_BYTE("e61-15.33", 0x100001, 0x20000, CRC(87909869) SHA1(7b90c23899a673966cac3352d375d17b83e66596) )

	ROM_REGION16_BE(0x1000000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks
	ROM_LOAD16_BYTE("e61-04.38", 0x400000, 0x200000, CRC(c27aec0c) SHA1(e95da2db07a20a53662ebd45c033966e8a22a15a) )	// C8 C9 CA CB
	ROM_LOAD16_BYTE("e61-05.39", 0x800000, 0x200000, CRC(83920d9d) SHA1(019e39ae85d1129f6d3b8460c4b1bd925f868ee2) )	// CC CD CE CF
	ROM_LOAD16_BYTE("e61-06.40", 0xc00000, 0x200000, CRC(2e717bfe) SHA1(1be54cd2ec65d8fd49a5c09b5d27791fd7a320d4) )	// D0 D1 D2 D3
ROM_END

ROM_START( pbobl2xh )
	ROM_REGION(0x200000, "maincpu", 0) /* 68020 code */
 	ROM_LOAD32_BYTE("e10-29.20", 0x000000, 0x40000, CRC(f1e9ad3f) SHA1(8689d85f30e075d21e4be01a2a097a850a921c47) )
	ROM_LOAD32_BYTE("e10-28.19", 0x000001, 0x40000, CRC(412a3602) SHA1(d754e6ac886676d2c1eb52de3a727894f316e6b5) )
	ROM_LOAD32_BYTE("e10-27.18", 0x000002, 0x40000, CRC(88cc0b5c) SHA1(bb08a7b8b37356376052ed03f8515677811823c0) )
	ROM_LOAD32_BYTE("e10-wrd.17", 0x000003, 0x40000, CRC(4bcc216b) SHA1(45e9250414201fa5ad866b32b0285973fd06367c) )

	ROM_REGION(0x400000, "gfx1" , 0) /* Sprites */
	ROM_LOAD16_BYTE("e10-02.rom", 0x000000, 0x100000, CRC(c0564490) SHA1(cbe9f880192c08f4d1db21d5ba14073b97e5f1d3) )
  	ROM_LOAD16_BYTE("e10-01.rom", 0x000001, 0x100000, CRC(8c26ff49) SHA1(cbb514c061106003d2ae2b6c43958b24feaad656) )
	ROM_FILL       (              0x200000, 0x200000, 0 )

	ROM_REGION(0x400000, "gfx2" , ROMREGION_ERASE00) /* Tiles */
	ROM_LOAD16_BYTE("e10-07.rom", 0x000000, 0x100000, CRC(dcb3c29b) SHA1(b80c3a8ce53d696c57675e654c9927ef8687759e) )
	ROM_LOAD16_BYTE("e10-06.rom", 0x000001, 0x100000, CRC(1b0f20e2) SHA1(66b44d059c2896abac2f0e7fc932489dee440ba0) )
	ROM_LOAD       ("e10-05.rom", 0x300000, 0x100000, CRC(81266151) SHA1(aa3b144f32995425db97efce440e234a3c7a6715) )

	ROM_REGION(0x180000, "taito_en:audiocpu", 0)	/* 68000 sound CPU */
	ROM_LOAD16_BYTE("e10-30.32", 0x100000, 0x40000, CRC(bb090c1e) SHA1(af2ff23d6f9bd56c25530cb9bf9f452b6f5210f5) )
	ROM_LOAD16_BYTE("e10-31.33", 0x100001, 0x40000, CRC(f4b88d65) SHA1(c74dcb4bed979039fad1d5c7528c14ce4db1d5ec) )

	ROM_REGION16_BE(0x800000, "ensoniq.0" , ROMREGION_ERASE00 )	// V2: 4 banks, only 2 populated
	ROM_LOAD16_BYTE("e10-04.rom", 0x000000, 0x200000, CRC(5c0862a6) SHA1(f916f63b8629239e3221e1e231e1b39962ef38ba) )	// C8 C9 CA CB
	ROM_LOAD16_BYTE("e10-03.rom", 0x400000, 0x200000, CRC(46d68ac8) SHA1(ad014e9f0d458308014959ca6823077f581ab088) )	// CC CD CE CF
ROM_END


GAME( 1997, arkretrh,  arkretrn, f3,      f3, taito_f3_state, arkretrn, ROT0,   "hack",     "Arkanoid Returns (World Hack)", MACHINE_SUPPORTS_SAVE )
GAME( 1996, cleopath,  cleopatr, f3_224a, f3, taito_f3_state, cleopatr, ROT0,   "hack",     "Cleopatra Fortune (World Hack)", MACHINE_SUPPORTS_SAVE )
GAME( 1994, driusgxh,  dariusg,  f3,      f3, taito_f3_state, dariusg,  ROT0,   "hack",     "Darius Gaiden (World Hack)", MACHINE_SUPPORTS_SAVE )
GAME( 2000, f3demo,    0,        f3,      f3, taito_f3_state, pbobble3, ROT0,   "Antiriad", "Demo - Taito F3", MACHINE_NOT_WORKING | MACHINE_SUPPORTS_SAVE )
GAME( 1995, gekiridh,  gekiridn, f3,      f3, taito_f3_state, gekirido, ROT270, "hack",     "Gekirindan (World Hack)", MACHINE_SUPPORTS_SAVE )
GAME( 1995, gekiridoc, gekiridn, f3,      f3, taito_f3_state, gekirido, ROT270, "Taito Corporation", "Gekirindan (Ver 2.3C 1995/09/21)", MACHINE_SUPPORTS_SAVE )
GAME( 1998, landmakh,  landmakr, f3,      f3, taito_f3_state, landmakr, ROT0,   "hack",     "Land Maker (World Hack)", MACHINE_SUPPORTS_SAVE )
GAME( 1995, pbobl2xh,  pbobble2, f3,      f3, taito_f3_state, pbobbl2x, ROT0,   "hack",     "Puzzle Bobble 2X (World Hack)", MACHINE_SUPPORTS_SAVE )
