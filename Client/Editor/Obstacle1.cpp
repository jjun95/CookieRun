#include "stdafx.h"
#include "Obstacle1.h"


CObstacle1::CObstacle1()
{
	m_tInfo = MAPINFO(63, 99);
}

CObstacle1::CObstacle1(MAPINFO & mapInfo)
	:CMaps(mapInfo)
{
}


CObstacle1::~CObstacle1()
{
}

void CObstacle1::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Obstacle1");
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
