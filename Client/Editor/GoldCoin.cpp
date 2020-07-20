#include "stdafx.h"
#include "GoldCoin.h"


CGoldCoin::CGoldCoin()
{
	m_tInfo = MAPINFO(58, 59);
}

CGoldCoin::CGoldCoin(MAPINFO & mapInfo)
	: CMaps(mapInfo)
{
}


CGoldCoin::~CGoldCoin()
{
}

void CGoldCoin::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"GoldCoin");
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
