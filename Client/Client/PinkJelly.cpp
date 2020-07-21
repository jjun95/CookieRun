#include "stdafx.h"
#include "PinkJelly.h"


CPinkJelly::CPinkJelly()
{
	m_tInfo = MAPINFO(BEARJL_CX, BEARJL_CY);
	m_eDTID = MAP::PINKJL;
}

CPinkJelly::CPinkJelly(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
}


CPinkJelly::~CPinkJelly()
{
}

void CPinkJelly::Update_Map()
{
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= 5.f;
	}
	CMaps::Update_Rect_Object();
}

void CPinkJelly::LateUpdate_Map()
{
}

void CPinkJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"PinkBear");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 0, 255));
}
