#include "stdafx.h"
#include "Main.h"
#include "Line_Manager.h"
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

	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Ground1.bmp", L"Ground1");
	
}

void CMain::Update_Main()
{
	CKey_Manager::Get_Instance()->Update_KeyManager();
	//CLine_Manager::Get_Instance()->Update_LineManager();
	CMap_Manager::Get_Instance()->Update_MapManager();
}

void CMain::Render_Main()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	//CLine_Manager::Get_Instance()->Render_LineManager(m_hDC); 
	CMap_Manager::Get_Instance()->Render_MapManager(m_hDC); 

}

void CMain::Release_Main()
{
	//CLine_Manager::Destroy_Instance(); 
	CMap_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 
}
