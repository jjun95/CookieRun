#include "stdafx.h"
#include "Obstacle1.h"


CObstacle1::CObstacle1()
{
	m_tInfo = MAPINFO(OTC1_CX, OTC1_CY);
	m_eDTID = MAP::OTC1;
}

CObstacle1::CObstacle1(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CObstacle1::~CObstacle1()
{
}

int CObstacle1::Update_Map()
{
	if (m_bIsDead)
		return OBJ_DEAD;
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= m_fSpeedInc;
	}
	CMaps::Update_Rect_Object();

	return OBJ_NOEVENT;
}

void CObstacle1::LateUpdate_Map()
{
	if (m_tRect.right + m_fSpeed <= 0)
		m_bIsDead = true;
}

void CObstacle1::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Obstacle1");
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

	//MoveToEx(hDC, m_tRect.left + m_fSpeed, m_tRect.top, nullptr);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.top);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.top);
}
