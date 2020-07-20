#include "stdafx.h"
#include "PinkJelly.h"


CPinkJelly::CPinkJelly()
{
	m_tInfo = MAPINFO(55, 51);
}

CPinkJelly::CPinkJelly(MAPINFO & mapInfo)
	: CMaps(mapInfo)
{
}


CPinkJelly::~CPinkJelly()
{
}

void CPinkJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"PinkBear");
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
