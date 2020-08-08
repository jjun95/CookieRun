#include "stdafx.h"
#include "Result.h"
#include "Scene_Manager.h"


CResult::CResult()
{
}

CResult::CResult(CObj * pPlayer)
	: CScene(pPlayer)
{
}


CResult::~CResult()
{
	Release_Scene();
}

void CResult::Ready_Scene()
{
	//Rectangle(hDC, 480, 592, 792, 689);
	m_tOKRect.left = 480;
	m_tOKRect.top = 592;
	m_tOKRect.right = 792;
	m_tOKRect.bottom = 689;
}

void CResult::Update_Scene()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	if (PtInRect(&m_tOKRect, pt)) {
		if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON)) {
			CObj::Set_MyCoin(m_pPlayer->Get_CurCoin());
			if (m_pPlayer->Get_BestScore() < m_pPlayer->Get_CurScore())
				CObj::Set_BestScore(m_pPlayer->Get_CurScore());
			CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_STANDBY, m_pPlayer);
		}
	}
}

void CResult::LateUpdate_Scene()
{
}

void CResult::Render_Scene(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Result");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetTextAlign(hDC, TA_RIGHT);

	HFONT hFont, oldFont;

	hFont = CreateFont(200, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Black"));

	TCHAR szScore[32] = L"";
	TCHAR szCoin[32] = L"";
	swprintf_s(szScore, L"%d",m_pPlayer->Get_CurScore());
	swprintf_s(szCoin, L"%d",m_pPlayer->Get_CurCoin());
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, 1000, 220, szScore, lstrlen(szScore));
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);

	hFont = CreateFont(80, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("CookieRun Black"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, 1000, 470, szCoin, lstrlen(szCoin));
	hFont = (HFONT)SelectObject(hDC, oldFont);
	DeleteObject(hFont);

}

void CResult::Release_Scene()
{
}
