#include "stdafx.h"
#include "SmallHp.h"


CSmallHp::CSmallHp()
{
	m_tInfo = MAPINFO(SMALLHP_CX, SMALLHP_CY);
	m_eDTID = MAP::SMALLHP;
}

CSmallHp::CSmallHp(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CSmallHp::~CSmallHp()
{
}

int CSmallHp::Update_Map()
{
	return 0;
}

void CSmallHp::LateUpdate_Map()
{
}

void CSmallHp::Render_Map(HDC hDC)
{
}
