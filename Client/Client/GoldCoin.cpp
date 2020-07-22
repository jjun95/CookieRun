#include "stdafx.h"
#include "GoldCoin.h"


CGoldCoin::CGoldCoin()
{
	m_tInfo = MAPINFO(GDCOIN_CX, GDCOIN_CY);
	m_eDTID = MAP::GDCOIN;
	m_iCValue = 10;
	m_iSValue = 600;
}

CGoldCoin::CGoldCoin(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iCValue = 10;
	m_iSValue = 600;
}


CGoldCoin::~CGoldCoin()
{
}

int CGoldCoin::Update_Map()
{
	if (m_bIsDead)
		return OBJ_DEAD;
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= m_fSpeedInc;
	}
	CMaps::Update_Rect_Object();

	return OBJ_NOEVENT;
}

void CGoldCoin::LateUpdate_Map()
{
	if (m_tRect.right + m_fSpeed <= 0)
		m_bIsDead = true;
}

void CGoldCoin::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"GoldCoin");
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
