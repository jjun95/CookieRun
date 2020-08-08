#include "stdafx.h"
#include "BaseJelly.h"
#include "Obj.h"


CBaseJelly::CBaseJelly()
{
	m_tInfo = MAPINFO(BASEJL_CX, BASEJL_CY);
	m_eDTID = MAP::BASEJL;
	m_iSValue = 385;
}

CBaseJelly::CBaseJelly(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iSValue = 385;
}


CBaseJelly::~CBaseJelly()
{
}

void CBaseJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BaseJelly");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		BASEJL_CX * (CObj::Get_JellyLevel() - 1), 0,
		BASEJL_CX,
		BASEJL_CY,
		RGB(255, 0, 255));
}
