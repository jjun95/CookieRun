#include "stdafx.h"
#include "BigJelly.h"


CBigJelly::CBigJelly()
{
	m_tInfo = MAPINFO(BIGJL_CX, BIGJL_CY);
	m_eDTID = MAP::BIGJL;
}

CBigJelly::CBigJelly(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: CMaps(mapInfo, eDTID)
{
	m_iSValue = 10000;
}


CBigJelly::~CBigJelly()
{
}

void CBigJelly::Render_Map(HDC hDC)
{
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BigJelly");
	if (nullptr == hMemDC)
		return;
	GdiTransparentBlt(hDC, m_tInfo.tPoint.fX - m_tInfo.tPoint.iCX / 2.f + m_fSpeed,
		m_tInfo.tPoint.fY - m_tInfo.tPoint.iCY / 2.f,
		m_tInfo.tPoint.iCX,
		m_tInfo.tPoint.iCY,
		hMemDC,
		0, 0,
		BIGJL_CX,
		BIGJL_CX,
		RGB(255, 0, 255));
}