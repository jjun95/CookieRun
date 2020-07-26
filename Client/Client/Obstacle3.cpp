#include "stdafx.h"
#include "Obstacle3.h"


CObstacle3::CObstacle3()
{
	m_tInfo = MAPINFO(OTC3_CX, OTC3_CY);
	m_eDTID = MAP::OTC3;
}

CObstacle3::CObstacle3(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CObstacle3::~CObstacle3()
{
}

void CObstacle3::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Obstacle3");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		OTC3_CX,
		OTC3_CY,
		RGB(255, 0, 255));

	//MoveToEx(hDC, m_tRect.left + m_fSpeed, m_tRect.top, nullptr);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.top);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.top);
}
