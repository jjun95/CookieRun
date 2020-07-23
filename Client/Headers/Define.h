#pragma once
#define		KEY_LEFT		0x00000001
#define		KEY_RIGHT		0x00000002 
#define		KEY_UP			0x00000004
#define		KEY_DOWN		0x00000008 
#define		KEY_LBUTTON		0x00000010 
#define		KEY_RBUTTON		0x00000020 
#define		KEY_BACKSPACE	0x00000040
//save
#define		KEY_S			0x00000080
//load
#define		KEY_L			0x00000100
//coin
#define		KEY_C			0x00000200
//jelly
#define		KEY_J			0x00000400
//obstacle
#define		KEY_O			0x00000800
//mapblock
#define		KEY_B			0x00001000
// item
#define		KEY_I			0x00002000

#define		KEY_1			0x00004000
#define		KEY_2			0x00008000
#define		KEY_3			0x00010000
#define		KEY_4			0x00200000
#define		KEY_5			0x00400000

#define WINCX 1280
#define WINCY 720

#define BLOCK_CX 120
#define BLOCK_CY 120
#define OTC1_CX 60
#define OTC1_CY 100
#define OTC2_CX 70
#define OTC2_CY 100
#define OTC3_CX 60
#define OTC3_CY 190
#define OTC4_CX 134
#define OTC4_CY 482
#define SVCOIN_CX 50
#define SVCOIN_CY 50
#define GDCOIN_CX 60
#define GDCOIN_CY 60
#define BIGCOIN_CX 160
#define BIGCOIN_CY 160
#define BASEJL_CX 50
#define BASEJL_CY 50
#define BEARJL_CX 50
#define BEARJL_CY 50
#define MIDJL_CX 75
#define MIDJL_CY 75
#define BIGJL_CX 125
#define BIGJL_CY 125
#define BIGHP_CX 110
#define BIGHP_CY 130
#define SMALLHP_CX 60
#define SMALLHP_CY 70
#define BOOSTER_CX 80
#define BOOSTER_CY 60
#define GIANT_CX 60
#define GIANT_CY 70
#define MAGNET_CX 60
#define MAGNET_CY 60

#define PLAYERSIZE 320
#define PETSIZE 198

#define OBJ_NOEVENT 0
#define OBJ_DEAD 1

#define PI 3.141592f
#define DEGREETORADIAN(Angle) Angle * PI / 180.f
#define GRAVITY 9.8f
#define DEFAULT_SPEED 8.f
