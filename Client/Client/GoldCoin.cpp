#include "stdafx.h"
#include "GoldCoin.h"


CGoldCoin::CGoldCoin()
{
	m_tInfo = MAPINFO(GDCOIN_CX, GDCOIN_CY);
	m_eDTID = MAP::GDCOIN;
	m_iCValue = 10;
	m_iSValue = 600;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 5;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}

CGoldCoin::CGoldCoin(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iCValue = 10;
	m_iSValue = 600;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 5;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}


CGoldCoin::~CGoldCoin()
{
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
		m_tInfo.tPoint.iCX * m_tFrame.iStartFrame, 0,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		RGB(255, 0, 255));
}
