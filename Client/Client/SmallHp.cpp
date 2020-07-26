#include "stdafx.h"
#include "SmallHp.h"


CSmallHp::CSmallHp()
{
	m_tInfo = MAPINFO(SMALLHP_CX, SMALLHP_CY);
	m_eDTID = MAP::SMALLHP;
	m_iSValue = 333;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}

CSmallHp::CSmallHp(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
	m_iSValue = 333;
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 150;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.dwFrameTime = GetTickCount();
}


CSmallHp::~CSmallHp()
{
}

void CSmallHp::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"SmallHp");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		SMALLHP_CX * m_tFrame.iStartFrame, SMALLHP_CY * m_tFrame.iSceneFrame,
		SMALLHP_CX,
		SMALLHP_CY,
		RGB(255, 0, 255));
}
