#include "stdafx.h"
#include "MapBlock.h"

CMapBlock::CMapBlock()
{
	m_tInfo = MAPINFO(124, 120);
}

CMapBlock::CMapBlock(MAPINFO & mapInfo)
	: CMaps(mapInfo)
{
}

CMapBlock::~CMapBlock()
{
}

void CMapBlock::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Ground1");
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
		RGB(255, 255, 255));
}
