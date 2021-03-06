#include "stdafx.h"
#include "MiddleJelly.h"


CMiddleJelly::CMiddleJelly()
{
	m_tInfo = MAPINFO(MIDJL_CX, MIDJL_CY);
	m_eDTID = MAP::MIDJL;
}

CMiddleJelly::CMiddleJelly(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
}


CMiddleJelly::~CMiddleJelly()
{
}

void CMiddleJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"MiddleJelly");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		MIDJL_CX,
		MIDJL_CY,
		RGB(255, 0, 255));
}