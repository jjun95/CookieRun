#include "stdafx.h"
#include "YellowJelly.h"


CYellowJelly::CYellowJelly()
{
	m_tInfo = MAPINFO(55, 51);
}

CYellowJelly::CYellowJelly(MAPINFO & mapInfo)
	: CMaps(mapInfo)
{
}


CYellowJelly::~CYellowJelly()
{
}

void CYellowJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"YellowBear");
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
