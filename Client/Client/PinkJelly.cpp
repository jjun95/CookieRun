#include "stdafx.h"
#include "PinkJelly.h"


CPinkJelly::CPinkJelly()
{
	m_tInfo = MAPINFO(BEARJL_CX, BEARJL_CY);
	m_eDTID = MAP::PINKJL;
	m_iSValue = 3600;
}

CPinkJelly::CPinkJelly(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iSValue = 3600;
}


CPinkJelly::~CPinkJelly()
{
}

int CPinkJelly::Update_Map()
{
	if (m_bIsDead)
		return OBJ_DEAD;
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= m_fSpeedInc;
	}
	CMaps::Update_Rect_Object();

	return OBJ_NOEVENT;
}

void CPinkJelly::LateUpdate_Map()
{
	if (m_tRect.right + m_fSpeed <= 0)
		m_bIsDead = true;
}

void CPinkJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"PinkBear");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 0, 255));
}
