#include "stdafx.h"
#include "Obj_Manager.h"
#include "Bitmap_Manager.h"
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
	m_tInfo.fY = m_pPlayer->Get_Rect()->bottom - 150;
	m_tInfo.iCX = PETSIZE;
	m_tInfo.iCY = PETSIZE;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 200;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
	m_eCurState = OBJ::PET_DEFAULT;
	m_eCurState = OBJ::PET_MAGNET;
}

int CPet::Update_Object()
{
	m_tInfo.fX = m_pPlayer->Get_Info()->fX - 100;
	m_tInfo.fY = m_pPlayer->Get_Rect()->bottom - 100;
	CObj::MoveFrame();
	return 0;
}

void CPet::LateUpdate_Object()
{
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
		m_tInfo.iCX * m_tFrame.iStartFrame, m_tInfo.iCY * m_tFrame.iSceneFrame,
		m_tInfo.iCX,
		m_tInfo.iCY,
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
