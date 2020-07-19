#include "stdafx.h"
#include "MapBlock.h"
#include "Bitmap_Manager.h"
#include "Scroll_Manager.h"

CMapBlock::CMapBlock()
{
	m_tInfo = MAPINFO(124, 120);
}

CMapBlock::CMapBlock(MAPINFO & mapInfo)
	: CMaps(mapInfo)
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
	m_tRect.left = m_tInfo.tPoint.fLeft;
	m_tRect.right = m_tInfo.tPoint.fLeft + m_tInfo.tPoint.iCX;
	m_tRect.top = m_tInfo.tPoint.fTop;
	m_tRect.bottom = m_tInfo.tPoint.fTop + m_tInfo.tPoint.iCY;
}

void CMapBlock::LateUpdate_Map()
{
	//if ( (m_tRect.right <= 0) || (m_tRect.left > WINCX))
	//	m_bIsDead = true;
	//else m_bIsDead = false;
}

void CMapBlock::Render_Map(HDC hDC)
{
	if (m_bIsDead == true)
		return;
	//Rectangle(hDC, m_tInfo.tPoint.fLeft, m_tInfo.tPoint.fTop, m_tInfo.tPoint.fLeft + MAPTILE_SIZE, m_tInfo.tPoint.fTop + MAPTILE_SIZE);
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Ground1");
	if (nullptr == hMemDC) 
		return;
	//int scX = CScroll_Manager::Get_ScrollX();
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fLeft + m_fSpeed,
		m_tInfo.tPoint.fTop,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 255, 255));

	m_tRect.left += m_fSpeed;
	m_tRect.right += m_fSpeed;
	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);
}