#include "stdafx.h"
#include "MapBlock.h"

CMapBlock::CMapBlock()
{
	m_tInfo = MAPINFO(124, 120);
}

CMapBlock::CMapBlock(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_dwTime = GetTickCount();
}

CMapBlock::~CMapBlock()
{
}

void CMapBlock::Update_Map()
{
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= 5.f;
	}
	CMaps::Update_Rect_Object();
}

void CMapBlock::LateUpdate_Map()
{
	//if ( (m_tRect.right <= 0) || (m_tRect.left > WINCX))
	//	m_bIsDead = true;
	//else m_bIsDead = false;
}

void CMapBlock::Render_Map(HDC hDC)
{
	//if (m_bIsDead == true)
	//	return;
	//Rectangle(hDC, m_tInfo.tPoint.fLeft, m_tInfo.tPoint.fTop, m_tInfo.tPoint.fLeft + MAPTILE_SIZE, m_tInfo.tPoint.fTop + MAPTILE_SIZE);
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Ground1");
	if (nullptr == hMemDC) 
		return;
	//int scX = CScroll_Manager::Get_ScrollX();
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 255, 255));

	MoveToEx(hDC, m_tRect.left + m_fSpeed, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.top);
	LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.bottom);
	LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.bottom);
	LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.top);
}