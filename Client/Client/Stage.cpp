#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Pet.h"
#include "Map_Manager.h"
#include "Obj_Manager.h"


CStage::CStage()
{
}

CStage::CStage(CObj * pPlayer)
	: CScene(pPlayer)
{
}


CStage::~CStage()
{
	Release_Scene();
}

void CStage::Ready_Scene()
{
	m_dwTime = GetTickCount();

	CObj* pObj = CAbstractFactory<CPet>::Create();
	CObj_Manager::Get_Instance()->Add_Object(pObj, OBJ::OBJ_PET);

	CMap_Manager::Get_Instance()->Load_MapData();
	CMap_Manager::Get_Instance()->Set_Pet(CObj_Manager::Get_Instance()->Get_Pet());

	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Hp(0, true);
}

void CStage::Update_Scene()
{
	CObj_Manager::Get_Instance()->Update_ObjectManager();
	CMap_Manager::Get_Instance()->Update_MapManager();
}

void CStage::LateUpdate_Scene()
{
	CObj_Manager::Get_Instance()->LateUpdate_ObjectManager();
	if (m_dwTime + 10 <= GetTickCount()) {
		m_iSpeed += 3;
	}
}

void CStage::Render_Scene(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Back01");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Back01-1");
	GdiTransparentBlt(hDC, 0,
		0,
		WINCX,
		WINCY,
		hMemDC,
		(m_iSpeed) % 640, 0,
		WINCX,
		WINCY,
		RGB(255, 0, 255));
	CMap_Manager::Get_Instance()->Render_MapManager(hDC);
	CObj_Manager::Get_Instance()->Render_ObjectManager(hDC);

	TCHAR szCoin[32] = L"";
	TCHAR szScore[32] = L"";
	TCHAR szHp[32] = L"";
	CObj* player = CObj_Manager::Get_Instance()->Get_Player();
	int coin = player->Get_CurCoin();
	int score = player->Get_CurScore();
	int hp = dynamic_cast<CPlayer*>(player)->Get_Hp();
	int maxHp = dynamic_cast<CPlayer*>(player)->Get_MaxHp();

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"HpBarBack");
	BitBlt(hDC, 70, 80, maxHp + 12, 34, hMemDC, 590 - maxHp, 0, SRCCOPY);
	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"HpBar");
	BitBlt(hDC, 70, 80, hp, 34, hMemDC, 0, 0, SRCCOPY);
	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"HpBarAcc");
	BitBlt(hDC, 70 + hp, 80, 10, 34, hMemDC, 0, 0, SRCCOPY);
	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SmallHp");
	GdiTransparentBlt(hDC, 20,
		55,
		60,
		70,
		hMemDC,
		0, 0,
		60,
		70,
		RGB(255, 0, 255));

	AddFontResourceW(L"../Font/CookieRun Black.ttf");

	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(255, 255, 255));
	HFONT hFont, oldFont;

	hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Black"));
	swprintf_s(szCoin, L"Coin %d", coin);
	swprintf_s(szScore, L"SCORE %d", score);
	oldFont = (HFONT)SelectObject(hDC, hFont);
	SetTextAlign(hDC, TA_LEFT);
	TextOut(hDC, WINCX>>1, 20, szCoin, lstrlen(szCoin));
	SetTextAlign(hDC, TA_RIGHT);
	TextOut(hDC, WINCX-50, 20, szScore, lstrlen(szScore));
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);
}

void CStage::Release_Scene()
{
	CMap_Manager::Get_Instance()->Release_MapManager();
	//CObj_Manager::Get_Instance()->Release_ObjectManager();
	CObj_Manager::Get_Instance()->Delete_Object(OBJ::OBJ_PET);
	RemoveFontResourceW(L"../Font/CookieRun Black.ttf");
}
