#include "stdafx.h"
#include "Booster.h"


CBooster::CBooster()
{
	m_tInfo = MAPINFO(BOOSTER_CX, BOOSTER_CY);
	m_eDTID = MAP::BOOSTER;
}

CBooster::CBooster(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}
CBooster::~CBooster()
{
}

void CBooster::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Booster");
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
