#include "stdafx.h"
#include "Main.h"
#include "Key_Manager.h"
#include "Map_Manager.h"
#include "Bitmap_Manager.h"

CMain::CMain()
{
}


CMain::~CMain()
{
	Release_Main(); 
}

void CMain::Ready_Main()
{
	m_hDC = GetDC(g_hWND);
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/BackBuffer.bmp", L"BackBuffer");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/Back01.bmp", L"Back01");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Ground1.bmp", L"Ground1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle1.bmp", L"Obstacle1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle2.bmp", L"Obstacle2");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle3.bmp", L"Obstacle3");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle4.bmp", L"Obstacle4");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/SilverCoin.bmp", L"SilverCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/GoldCoin.bmp", L"GoldCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/BigCoin.bmp", L"BigCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/PinkBear.bmp", L"PinkBear");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/YellowBear.bmp", L"YellowBear");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/TestJelly.bmp", L"BaseJelly");
	
}

void CMain::Update_Main()
{
	CKey_Manager::Get_Instance()->Update_KeyManager();
	//CLine_Manager::Get_Instance()->Update_LineManager();
	CMap_Manager::Get_Instance()->Update_MapManager();
}

void CMain::Render_Main()
{
	HDC hBack = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BackBuffer");
	if (nullptr == hBack)
		return;
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Back01");
	BitBlt(hBack, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	//CLine_Manager::Get_Instance()->Render_LineManager(m_hDC); 
	CMap_Manager::Get_Instance()->Render_MapManager(hBack); 
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBack, 0, 0, SRCCOPY);

}

void CMain::Release_Main()
{
	//CLine_Manager::Destroy_Instance(); 
	CMap_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 
}
