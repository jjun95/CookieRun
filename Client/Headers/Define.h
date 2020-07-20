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

#define		KEY_1			0x00002000
#define		KEY_2			0x00004000
#define		KEY_3			0x00008000
#define		KEY_4			0x00010000

#define WINCX 1280
#define WINCY 720

#define PLAYERSIZE 320

#define OBJ_NOEVENT 0
#define OBJ_DEAD 1

#define PI 3.141592f
#define DEGREETORADIAN(Angle) Angle * PI / 180.f
#define GRAVITY 9.8f
