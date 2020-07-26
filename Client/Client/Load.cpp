#include "stdafx.h"
#include "Load.h"=
#include "Obj_Manager.h"
#include "Scene_Manager.h"
#include "Bitmap_Manager.h"


CLoad::CLoad()
{
}


CLoad::~CLoad()
{
}

void CLoad::Ready_Scene()
{
	m_dwTime = GetTickCount();
}

void CLoad::Update_Scene()
{
	//CObj_Manager::Get_Instance()->Update_ObjectManager();
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_ENTER))
		CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_PLAY, m_pPlayer);
}

void CLoad::LateUpdate_Scene()
{
	//CObj_Manager::Get_Instance()->LateUpdate_ObjectManager();
}

void CLoad::Render_Scene(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Load");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	
	AddFontResourceW(L"../Font/CookieRun Regular.ttf");
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(255, 255, 255));
	SetTextAlign(hDC, TA_CENTER);

	HFONT hFont, oldFont;

	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Regular"));
	TCHAR szNotice[128] = L""; 
		swprintf_s(szNotice, L"Jusin Game Academy");
	if (m_dwTime + 1500 < GetTickCount())
		swprintf_s(szNotice, L"3개월차 API 발표");
	if (m_dwTime + 3000 < GetTickCount())
		swprintf_s(szNotice, L"by 110C기 전선아");
	if (m_dwTime + 4500 < GetTickCount())
		swprintf_s(szNotice, L"Enter 키를 누르면 시작합니다");

	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, WINCX >> 1, 640, szNotice, lstrlen(szNotice));
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);
}

void CLoad::Release_Scene()
{
}
