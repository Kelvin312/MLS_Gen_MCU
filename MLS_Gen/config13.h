#ifndef CONFIG13_H_
#define CONFIG13_H_

const u16 clockDividor = 4; //�������� ������� �������
const u16 repeatMls = 5; //���������� �������� � ������������������
const u16 feedbacksSize = 1; //���������� � �������������������
PROGMEM const u32 feedbacks[] = //����� �������� ������
{
	0x000010CE, //!
	0x0000100D,
	0x00001013,
	0x0000101A,
	0x00001029,
	0x00001032,
	0x00001037,
	0x00001045,
	0x00001046,
	0x0000104F,
	0x00001052,
	0x00001057,
	0x0000105D,
	0x0000105E,
	0x00001061,
	0x00001064,
	0x00001070,
	0x00001079,
	0x00001086,
	0x0000108A,
	0x00001094,
	0x00001097,
	0x0000109D,
	0x000010A1,
	0x000010B3,
	0x000010B5,
	0x000010BC,
	0x000010C4,
	0x000010CB,
	0x000010CE,
	0x000010DF,
	0x000010E0,
	0x000010E3,
	0x000010E6,
	0x000010EF,
	0x000010F1,
	0x000010F8,
	0x000010FD,
	0x0000110C,
	0x00001112,
	0x0000111B,
	0x0000111E,
	0x00001121,
	0x0000112D,
	0x0000112E,
	0x0000113C,
	0x0000113F,
	0x00001144,
	0x0000114B,
	0x0000114D,
	0x00001159,
	0x0000115F,
	0x00001166,
	0x00001177,
	0x0000117B,
	0x0000117D,
	0x00001182,
	0x00001193,
	0x00001195,
	0x000011A3,
	0x000011AA,
	0x000011AC,
	0x000011B7,
	0x000011B8,
	0x000011BE,
	0x000011C3,
	0x000011C6,
	0x000011CA,
	0x000011D1,
	0x000011D4,
	0x000011D8,
	0x000011DB,
	0x000011DD,
	0x000011F0,
	0x000011F6,
	0x000011FC,
	0x00001205,
	0x00001209,
	0x0000120F,
	0x00001212,
	0x00001214,
	0x0000121E,
	0x00001228,
	0x0000122B,
	0x00001230,
	0x00001236,
	0x0000123F,
	0x00001241,
	0x0000124D,
	0x0000124E,
	0x0000125A,
	0x0000125F,
	0x00001260,
	0x00001263,
	0x00001265,
	0x00001271,
	0x00001284,
	0x0000128B,
	0x0000128E,
	0x00001290,
	0x00001296,
	0x0000129C,
	0x000012A9,
	0x000012AA,
	0x000012B1,
	0x000012B8,
	0x000012BB,
	0x000012C3,
	0x000012C5,
	0x000012CA,
	0x000012CC,
	0x000012CF,
	0x000012D7,
	0x000012DE,
	0x000012E2,
	0x000012E7,
	0x000012EB,
	0x000012F5,
	0x00001301,
	0x00001302,
	0x00001308,
	0x00001316,
	0x0000131F,
	0x00001325,
	0x00001329,
	0x0000132C,
	0x00001334,
	0x0000133B,
	0x0000133D,
	0x00001343,
	0x00001349,
	0x0000134C,
	0x00001358,
	0x0000135B,
	0x0000135E,
	0x00001361,
	0x00001375,
	0x0000137A,
	0x00001389,
	0x00001394,
	0x0000139D,
	0x000013A7,
	0x000013AB,
	0x000013AE,
	0x000013B5,
	0x000013B9,
	0x000013BC,
	0x000013C1,
	0x000013C8,
	0x000013D0,
	0x000013DC,
	0x000013E3,
	0x000013E5,
	0x000013EF,
	0x000013F7,
	0x000013F8,
	0x00001403,
	0x0000140C,
	0x0000140F,
	0x00001411,
	0x00001418,
	0x0000141D,
	0x0000141E,
	0x00001422,
	0x00001433,
	0x0000143A,
	0x00001442,
	0x00001455,
	0x00001456,
	0x0000145F,
	0x00001466,
	0x0000146A,
	0x0000146F,
	0x00001471,
	0x00001474,
	0x0000147D,
	0x00001484,
	0x00001487,
	0x00001488,
	0x0000148D,
	0x00001495,
	0x0000149A,
	0x0000149F,
	0x000014A0,
	0x000014A5,
	0x000014AA,
	0x000014BB,
	0x000014BE,
	0x000014C0,
	0x000014C9,
	0x000014CF,
	0x000014D7,
	0x000014DB,
	0x000014DE,
	0x000014E1,
	0x000014EB,
	0x000014F9,
	0x000014FA,
	0x00001501,
	0x00001507,
	0x0000150E,
	0x00001510,
	0x00001519,
	0x0000151A,
	0x00001526,
	0x00001534,
	0x00001537,
	0x00001538,
	0x0000153D,
	0x0000153E,
	0x00001552,
	0x00001554,
	0x00001558,
	0x00001562,
	0x0000156B,
	0x0000156D,
	0x00001575,
	0x00001579,
	0x00001580,
	0x0000158A,
	0x00001591,
	0x00001592,
	0x00001597,
	0x0000159B,
	0x000015A1,
	0x000015A4,
	0x000015B6,
	0x000015BF,
	0x000015C2,
	0x000015CB,
	0x000015CD,
	0x000015D6,
	0x000015D9,
	0x000015EC,
	0x000015F2,
	0x000015FE,
	0x00001607,
	0x00001610,
	0x00001615,
	0x00001616,
	0x0000161F,
	0x00001620,
	0x00001626,
	0x00001638,
	0x00001645,
	0x00001646,
	0x0000164A,
	0x00001651,
	0x00001657,
	0x0000165E,
	0x00001662,
	0x00001668,
	0x0000166B,
	0x00001670,
	0x00001673,
	0x00001675,
	0x00001686,
	0x0000168C,
	0x00001694,
	0x00001697,
	0x0000169B,
	0x0000169D,
	0x000016A2,
	0x000016AD,
	0x000016B3,
	0x000016BA,
	0x000016C4,
	0x000016C7,
	0x000016D3,
	0x000016D5,
	0x000016DA,
	0x000016F1,
	0x000016F8,
	0x000016FE,
	0x00001703,
	0x00001709,
	0x0000170A,
	0x00001714,
	0x00001724,
	0x00001727,
	0x0000172D,
	0x0000172E,
	0x00001730,
	0x00001735,
	0x00001747,
	0x00001748,
	0x0000174B,
	0x0000174E,
	0x00001755,
	0x00001759,
	0x0000175C,
	0x0000176F,
	0x0000177D,
	0x0000177E,
	0x00001782,
	0x00001784,
	0x00001788,
	0x0000178B,
	0x0000179F,
	0x000017A0,
	0x000017A5,
	0x000017A6,
	0x000017AC,
	0x000017AF,
	0x000017B2,
	0x000017B4,
	0x000017CA,
	0x000017D2,
	0x000017D7,
	0x000017D8,
	0x000017E7,
	0x000017EE,
	0x000017F3,
	0x000017F6,
	0x000017FA,
	0x000017FF,
	0x00001803,
	0x0000180A,
	0x0000180C,
	0x00001817,
	0x00001824,
	0x00001827,
	0x00001833,
	0x0000183C,
	0x0000183F,
	0x00001848,
	0x00001850,
	0x0000185A,
	0x0000185F,
	0x00001860,
	0x00001869,
	0x0000186C,
	0x00001872,
	0x00001877,
	0x00001882,
	0x00001887,
	0x0000189A,
	0x000018A3,
	0x000018A6,
	0x000018AF,
	0x000018B1,
	0x000018B8,
	0x000018BD,
	0x000018D1,
	0x000018D4,
	0x000018DB,
	0x000018E2,
	0x000018E4,
	0x000018ED,
	0x000018F0,
	0x000018F5,
	0x000018F6,
	0x000018F9,
	0x000018FF,
	0x00001904,
	0x00001907,
	0x0000190E,
	0x00001913,
	0x0000191C,
	0x00001925,
	0x00001929,
	0x0000192C,
	0x00001932,
	0x00001940,
	0x00001949,
	0x0000194C,
	0x0000194F,
	0x00001954,
	0x0000195B,
	0x0000195D,
	0x00001961,
	0x0000196B,
	0x0000196D,
	0x00001973,
	0x00001983,
	0x0000198A,
	0x00001997,
	0x000019A8,
	0x000019AE,
	0x000019BA,
	0x000019CB,
	0x000019CD,
	0x000019D5,
	0x000019DC,
	0x000019E0,
	0x000019E3,
	0x000019EA,
	0x000019F1,
	0x000019F2,
	0x000019FB,
	0x000019FD,
	0x00001A04,
	0x00001A0D,
	0x00001A13,
	0x00001A20,
	0x00001A26,
	0x00001A2F,
	0x00001A34,
	0x00001A3B,
	0x00001A3D,
	0x00001A43,
	0x00001A49,
	0x00001A4C,
	0x00001A52,
	0x00001A5E,
	0x00001A64,
	0x00001A6D,
	0x00001A73,
	0x00001A7C,
	0x00001A86,
	0x00001A8F,
	0x00001A92,
	0x00001A98,
	0x00001A9B,
	0x00001AA2,
	0x00001AA7,
	0x00001AAE,
	0x00001AB6,
	0x00001AB9,
	0x00001ABF,
	0x00001ACE,
	0x00001AD0,
	0x00001ADC,
	0x00001AE6,
	0x00001AEA,
	0x00001AEC,
	0x00001AF1,
	0x00001AF4,
	0x00001AF7,
	0x00001B00,
	0x00001B05,
	0x00001B0F,
	0x00001B12,
	0x00001B17,
	0x00001B1D,
	0x00001B24,
	0x00001B28,
	0x00001B2D,
	0x00001B39,
	0x00001B3A,
	0x00001B48,
	0x00001B4D,
	0x00001B4E,
	0x00001B56,
	0x00001B65,
	0x00001B69,
	0x00001B6A,
	0x00001B71,
	0x00001B77,
	0x00001B82,
	0x00001B87,
	0x00001B8D,
	0x00001B90,
	0x00001B96,
	0x00001B9C,
	0x00001BA0,
	0x00001BA3,
	0x00001BA9,
	0x00001BB8,
	0x00001BBB,
	0x00001BC5,
	0x00001BCA,
	0x00001BCC,
	0x00001BD1,
	0x00001BE2,
	0x00001BE7,
	0x00001BE8,
	0x00001BEB,
	0x00001BEE,
	0x00001BF0,
	0x00001BF9,
	0x00001C01,
	0x00001C02,
	0x00001C0B,
	0x00001C0E,
	0x00001C13,
	0x00001C19,
	0x00001C25,
	0x00001C2C,
	0x00001C34,
	0x00001C38,
	0x00001C51,
	0x00001C58,
	0x00001C5D,
	0x00001C64,
	0x00001C67,
	0x00001C70,
	0x00001C79,
	0x00001C7C,
	0x00001C80,
	0x00001C83,
	0x00001C85,
	0x00001C89,
	0x00001C98,
	0x00001CA7,
	0x00001CB3,
	0x00001CB6,
	0x00001CC1,
	0x00001CC2,
	0x00001CCB,
	0x00001CD0,
	0x00001CD3,
	0x00001CD6,
	0x00001CE5,
	0x00001CE6,
	0x00001CE9,
	0x00001CF7,
	0x00001CFB,
	0x00001CFE,
	0x00001D03,
	0x00001D14,
	0x00001D17,
	0x00001D1E,
	0x00001D28,
	0x00001D2E,
	0x00001D30,
	0x00001D33,
	0x00001D39,
	0x00001D3A,
	0x00001D44,
	0x00001D5C,
	0x00001D5F,
	0x00001D66,
	0x00001D69,
	0x00001D6A,
	0x00001D6F,
	0x00001D72,
	0x00001D74,
	0x00001D7D,
	0x00001D88,
	0x00001D95,
	0x00001D96,
	0x00001D9A,
	0x00001D9F,
	0x00001DA9,
	0x00001DAC,
	0x00001DB1,
	0x00001DB2,
	0x00001DB7,
	0x00001DB8,
	0x00001DBB,
	0x00001DC5,
	0x00001DCC,
	0x00001DD2,
	0x00001DD4,
	0x00001DDB,
	0x00001DDD,
	0x00001DE8,
	0x00001DF3,
	0x00001DF9,
	0x00001DFF,
	0x00001E06,
	0x00001E09,
	0x00001E0A,
	0x00001E0F,
	0x00001E11,
	0x00001E12,
	0x00001E1D,
	0x00001E27,
	0x00001E2E,
	0x00001E36,
	0x00001E41,
	0x00001E47,
	0x00001E4E,
	0x00001E53,
	0x00001E55,
	0x00001E5C,
	0x00001E63,
	0x00001E74,
	0x00001E7D,
	0x00001E7E,
	0x00001E81,
	0x00001E8B,
	0x00001E8D,
	0x00001E90,
	0x00001E96,
	0x00001E99,
	0x00001E9A,
	0x00001EA0,
	0x00001EA6,
	0x00001EB2,
	0x00001EB4,
	0x00001EBE,
	0x00001EC0,
	0x00001ECA,
	0x00001ED8,
	0x00001EDB,
	0x00001EE1,
	0x00001EE8,
	0x00001EED,
	0x00001EF3,
	0x00001EF5,
	0x00001EFC,
	0x00001F02,
	0x00001F04,
	0x00001F07,
	0x00001F0D,
	0x00001F15,
	0x00001F1F,
	0x00001F20,
	0x00001F29,
	0x00001F32,
	0x00001F34,
	0x00001F45,
	0x00001F51,
	0x00001F5E,
	0x00001F62,
	0x00001F6B,
	0x00001F6E,
	0x00001F70,
	0x00001F7C,
	0x00001F86,
	0x00001F8C,
	0x00001F8F,
	0x00001F92,
	0x00001F9B,
	0x00001F9E,
	0x00001FA1,
	0x00001FA2,
	0x00001FA4,
	0x00001FA8,
	0x00001FAB,
	0x00001FB0,
	0x00001FC1,
	0x00001FC4,
	0x00001FC8,
	0x00001FD5,
	0x00001FDA,
	0x00001FF1,
	0x00001FFB,
	0x00001FFE
};



#endif /* CONFIG13_H_ */