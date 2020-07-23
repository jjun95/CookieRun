#include "stdafx.h"
#include "Obstacle2.h"


CObstacle2::CObstacle2()
{
	m_tInfo = MAPINFO(OTC2_CX, OTC2_CY);
	m_eDTID = MAP::OTC2;
}

CObstacle2::CObstacle2(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CObstacle2::~CObstacle2()
{
}

void CObstacle2::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Obstacle2");
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
