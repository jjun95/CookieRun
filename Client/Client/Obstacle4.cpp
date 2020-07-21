#include "stdafx.h"
#include "Obstacle4.h"


CObstacle4::CObstacle4()
{
	m_tInfo = MAPINFO(OTC4_CX, OTC4_CY);
	m_eDTID = MAP::OTC4;
}

CObstacle4::CObstacle4(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CObstacle4::~CObstacle4()
{
}

void CObstacle4::Update_Map()
{
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= 5.f;
	}
	CMaps::Update_Rect_Object();
}

void CObstacle4::LateUpdate_Map()
{
}

void CObstacle4::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Obstacle4");
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
