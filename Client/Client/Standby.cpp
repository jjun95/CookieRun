#include "stdafx.h"
#include "Standby.h"
#include "Scene_Manager.h"
#include "Player.h"

CStandby::CStandby()
{
}

CStandby::CStandby(CObj * pPlayer)
	: CScene(pPlayer)
{
}


CStandby::~CStandby()
{
	Release_Scene();
}

void CStandby::Ready_Scene()
{
	//Rectangle(hDC, 115, 130, 335, 595);
	//Rectangle(hDC, 360, 130, 580, 595);
	m_tHpRect.left = 115;
	m_tHpRect.top = 130;
	m_tHpRect.right = 335;
	m_tHpRect.bottom = 595;
	m_tJellyRect.left = 360;
	m_tJellyRect.top = 130;
	m_tJellyRect.right = 580;
	m_tJellyRect.bottom = 595;
	m_tUpgradeRect.left = 950;
	m_tUpgradeRect.top = 320;
	m_tUpgradeRect.right = 1168;
	m_tUpgradeRect.bottom = 390;
	m_tStartRect.left = 800;
	m_tStartRect.top = 550;
	m_tStartRect.right = 1100;
	m_tStartRect.bottom = 628;

	m_pPlayer->Set_Coin(0, true);
	m_pPlayer->Set_Score(0, true);
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Hp(0, true);
	m_iCoin = CObj::Get_TotalCoin();
	m_iLevel = CObj::Get_HpLevel();
}

void CStandby::Update_Scene()
{
	m_iCoin = CObj::Get_TotalCoin();
}

void CStandby::LateUpdate_Scene()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	if (PtInRect(&m_tHpRect, pt)) {
		if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON)) {
			m_iClicked = 0;
			//m_iLevel = CObj::Get_HpLevel();
		}
	}else if (PtInRect(&m_tJellyRect, pt)) {
		if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON)) {
			m_iClicked = 1;
			//m_iLevel = CObj::Get_JellyLevel();
		}
	}
	else if (PtInRect(&m_tUpgradeRect, pt)) {
		if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON)) {
			if (m_iIsEnough && m_iLevel < 10) {
				CObj::Set_MyCoin(-1000 * m_iLevel);
				if (m_iClicked == 0)
					CObj::HP_LevelUp();
				else CObj::Jelly_LevelUp();
			}
		}
	}
	else if (PtInRect(&m_tStartRect, pt)) {
		if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON))
			CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_PLAY, m_pPlayer);
	}

	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_1)) {
		m_pPlayer->Set_MyCoin(10000);
	}

	if (m_iClicked == 0)
		m_iLevel = CObj::Get_HpLevel();
	else
		m_iLevel = CObj::Get_JellyLevel();

	if (m_iLevel * 1000 > m_iCoin || m_iLevel >= 10)
		m_iIsEnough = 0;
	else m_iIsEnough = 1;
}

void CStandby::Render_Scene(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"UpgradeBack");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"UpgradePan");
	GdiTransparentBlt(hDC, 80,
		50,
		532,
		648,
		hMemDC,
		532 * m_iClicked, 0,
		532,
		648,
		RGB(255, 0, 255));

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Start");
	GdiTransparentBlt(hDC, 800,
		550,
		300,
		78,
		hMemDC,
		0, 0,
		300,
		78,
		RGB(255, 0, 255));

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Upgrade");
	GdiTransparentBlt(hDC, 950,
		320,
		218,
		70,
		hMemDC,
		218 * m_iIsEnough, 0,
		218,
		70,
		RGB(255, 0, 255));

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Selected");
	GdiTransparentBlt(hDC, 750,
		220,
		148,
		148,
		hMemDC,
		0, 0,
		148,
		148,
		RGB(255, 0, 255));

	// HP 업그레이드 hp 그림
	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SmallHp");
	GdiTransparentBlt(hDC, 170,
		250,
		120,
		140,
		hMemDC,
		0, 0,
		60,
		70,
		RGB(255, 0, 255));

	// 젤리 업그레이드 젤리 그림
	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BaseJelly");
	GdiTransparentBlt(hDC, 410,
		260,
		120,
		120,
		hMemDC,
		60 * (CObj::Get_JellyLevel() - 1), 0,
		60,
		60,
		RGB(255, 0, 255));

	hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SilverCoin");
	GdiTransparentBlt(hDC, 970,
		260,
		50,
		50,
		hMemDC,
		0, 0,
		50,
		50,
		RGB(255, 0, 255));

	if (m_iClicked == 0) {
		hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SmallHp");
		GdiTransparentBlt(hDC, 795,
			260,
			60,
			70,
			hMemDC,
			0, 0,
			60,
			70,
			RGB(255, 0, 255));
	}
	else {
		hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BaseJelly");
		GdiTransparentBlt(hDC, 790,
			265,
			60,
			60,
			hMemDC,
			60 * (CObj::Get_JellyLevel() - 1), 0,
			60,
			60,
			RGB(255, 0, 255));
	}

	AddFontResourceW(L"../Font/CookieRun Black.ttf");
	AddFontResourceW(L"../Font/CookieRun Regular.ttf");
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(255, 255, 255));
	SetTextAlign(hDC, TA_RIGHT);

	HFONT hFont, oldFont;

	hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Black"));
	TCHAR szCoin[32] = L"";
	TCHAR szBestScore[64] = L"";
	TCHAR szHpLevel[16] = L"";
	TCHAR szJellyLevel[16] = L"";
	TCHAR szInformation[128] = L"";
	TCHAR szNeedCoin[16] = L"";

	swprintf_s(szCoin, L"%d", CObj::Get_TotalCoin());
	swprintf_s(szBestScore, L"%d", CObj::Get_BestScore());
	swprintf_s(szHpLevel, L"Lv. %d", CObj::Get_HpLevel());
	swprintf_s(szJellyLevel, L"Lv. %d", CObj::Get_JellyLevel());
	swprintf_s(szNeedCoin, L"%d", m_iLevel * 1000);

	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, 1070, 47, szCoin, lstrlen(szCoin));
	TextOut(hDC, 270, 500, szHpLevel, lstrlen(szHpLevel));
	TextOut(hDC, 510, 500, szJellyLevel, lstrlen(szJellyLevel));
	TextOut(hDC, 1130, 260, szNeedCoin, lstrlen(szNeedCoin));
	SetTextColor(hDC, RGB(0, 0, 0));
	TextOut(hDC, 540, 615, szBestScore, lstrlen(szBestScore));
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);

	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Regular"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	SetTextColor(hDC, RGB(255, 255, 255));

	if (m_iClicked == 0) {
		swprintf_s(szInformation, L"최대 체력을 %d 올려줍니다", m_iLevel * 10);
		TextOut(hDC, 1180, 220, szInformation, lstrlen(szInformation));
	}
	else {
		swprintf_s(szInformation, L"기본젤리 점수를 %d 올려줍니다", m_iLevel * 50);
		TextOut(hDC, 1200, 220, szInformation, lstrlen(szInformation));
	}
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);

	//Rectangle(hDC, 115, 130, 335, 595);
	//Rectangle(hDC, 360, 130, 580, 595);
}

void CStandby::Release_Scene()
{
}
