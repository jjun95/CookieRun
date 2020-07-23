#include "stdafx.h"
#include "Giant.h"


CGiant::CGiant()
{
	m_tInfo = MAPINFO(GIANT_CX, GIANT_CY);
	m_eDTID = MAP::GIANT;
}
CGiant::CGiant(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}

CGiant::~CGiant()
{
}

void CGiant::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Giant");
	if (nullptr == hMemDC)
		return;
	int scX = CScroll_Manager::Get_ScrollX();
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + scX,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 0, 255));
}
