#include "stdafx.h"
#include "Magnet.h"


CMagnet::CMagnet()
{
	m_tInfo = MAPINFO(MAGNET_CX, MAGNET_CY);
	m_eDTID = MAP::MAGNET;
}

CMagnet::CMagnet(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
}

CMagnet::~CMagnet()
{
}

void CMagnet::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Magnet");
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
