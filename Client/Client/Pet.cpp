#include "stdafx.h"
#include "Obj_Manager.h"
#include "Bitmap_Manager.h"
#include "Map_Manager.h"
#include "Pet.h"


CPet::CPet()
{
}


CPet::~CPet()
{
}

void CPet::Ready_Object()
{
	m_pPlayer = CObj_Manager::Get_Instance()->Get_Player();
	m_tInfo.fX = m_pPlayer->Get_Info()->fX - 100;
	m_tInfo.fY = m_pPlayer->Get_Rect()->bottom - 100;
	m_tInfo.iCX = PETSIZE;
	m_tInfo.iCY = PETSIZE;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 200;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
	m_eCurState = OBJ::PET_DEFAULT;
	m_eNextState = OBJ::PET_DEFAULT;
}

int CPet::Update_Object()
{
	if (m_bIsMagnet) {
		float dx = (WINCX >> 1) - m_tInfo.fX;
		float dy = ((WINCY - 120) >> 1) - m_tInfo.fY;
		float dist = sqrtf(dx*dx + dy * dy);
		if (dx > 0) {
			m_tInfo.fX += 5 * dx / dist;
		}
		if (dy != 0) {
			m_tInfo.fY += 5 * dy / dist;
		}
	} 
	else {
		float dx = m_pPlayer->Get_Info()->fX - 100 - m_tInfo.fX;
		float dy = m_pPlayer->Get_Rect()->bottom - 100 - m_tInfo.fY;
		float dist = sqrt(dx*dx + dy * dy);
		if (dx < 0) {
			m_tInfo.fX += 10 * dx / dist;
			m_tInfo.fY += 10 * dy / dist;
		}
		else {
			m_tInfo.fX = m_pPlayer->Get_Info()->fX - 100;
			m_tInfo.fY = m_pPlayer->Get_Rect()->bottom - 100;
		}
	}
	Animation_Change();
	CObj::MoveFrame();
	return 0;
}

void CPet::LateUpdate_Object()
{
	if (m_dwMagnetTime + 4000 < GetTickCount()) {
		CMap_Manager::Get_Instance()->Set_Magnet(false);
		m_bIsMagnet = false;
		m_eNextState = OBJ::PET_DEFAULT;
	}
}

void CPet::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(m_tInfo.fX - (m_tInfo.iCX >> 3), m_tInfo.fY - (m_tInfo.iCY >> 3), m_tInfo.fX + (m_tInfo.iCX >> 3), m_tInfo.fY + (m_tInfo.iCY >> 3));
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Dumbbell");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.fX - (PETSIZE >> 1),
		m_tInfo.fY - (PETSIZE >> 1),
		m_tInfo.iCX,
		m_tInfo.iCY,
		hMemDC,
		PETSIZE * m_tFrame.iStartFrame, PETSIZE * m_tFrame.iSceneFrame,
		PETSIZE,
		PETSIZE,
		RGB(255, 0, 255));

	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);
}

void CPet::Release_Object()
{
}

void CPet::Animation_Change()
{
	if (m_eCurState != m_eNextState) {
		switch (m_eNextState) {
		case OBJ::PET_DEFAULT:
			m_tFrame.iDefaultStartFrame = 0;
			m_tFrame.iStartFrame = 0;
			m_tFrame.iEndFrame = 3;
			m_tFrame.dwFrameSpeed = 200;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJ::PET_MAGNET:
			m_tFrame.iDefaultStartFrame = 0;
			m_tFrame.iStartFrame = 0;
			m_tFrame.iEndFrame = 3;
			m_tFrame.dwFrameSpeed = 200;
			m_tFrame.iSceneFrame = 1;
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
