#include "stdafx.h"
#include "SilverCoin.h"


CSilverCoin::CSilverCoin()
{
	m_tInfo = MAPINFO(SVCOIN_CX, SVCOIN_CY);
	m_eDTID = MAP::SVCOIN;
	m_iCValue = 1;
	m_iSValue = 200;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}

CSilverCoin::CSilverCoin(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iCValue = 1;
	m_iSValue = 200;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}


CSilverCoin::~CSilverCoin()
{
}
void CSilverCoin::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SilverCoin");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		m_tInfo.tPoint.iCX * m_tFrame.iStartFrame, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 0, 255));
	//MoveToEx(hDC, m_tRect.left + m_fSpeed, m_tRect.top, nullptr);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.top);
	//LineTo(hDC, m_tRect.right + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.bottom);
	//LineTo(hDC, m_tRect.left + m_fSpeed, m_tRect.top);
}
