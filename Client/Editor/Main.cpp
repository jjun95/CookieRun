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
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/MiddleJelly.bmp", L"MiddleJelly");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/BigJelly.bmp", L"BigJelly");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/SmallHp.bmp", L"SmallHp");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/BigHp.bmp", L"BigHp");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Booster.bmp", L"Booster");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Giant.bmp", L"Giant");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Magnet.bmp", L"Magnet");
	
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

	TextOut(m_hDC, 10, 10, L"Save : S", 8);
	TextOut(m_hDC, 10, 30, L"Load: L", 7);
	TextOut(m_hDC, 10, 50, L"MapBlock : B", 12);
	TextOut(m_hDC, 10, 70, L"Coin : C", 8);
	TextOut(m_hDC, 10, 90, L"Jelly : J", 9);
	TextOut(m_hDC, 10, 110, L"Obstacle : O", 12);
	TextOut(m_hDC, 10, 130, L"Item : I", 8);

}

void CMain::Release_Main()
{
	//CLine_Manager::Destroy_Instance(); 
	CMap_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 
}
