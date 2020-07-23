#include "stdafx.h"
#include "BigCoin.h"


CBigCoin::CBigCoin()
{
	m_tInfo = MAPINFO(BIGCOIN_CX, BIGCOIN_CY);
	m_eDTID = MAP::BIGCOIN;
	m_iCValue = 100;
	m_iSValue = 700;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 250;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}

CBigCoin::CBigCoin(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iCValue = 100;
	m_iSValue = 700;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 250;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}


CBigCoin::~CBigCoin()
{
}

void CBigCoin::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BigCoin");
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
