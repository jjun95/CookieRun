#include "stdafx.h"
#include "Booster.h"


CBooster::CBooster()
{
	m_tInfo = MAPINFO(BOOSTER_CX, BOOSTER_CY);
	m_eDTID = MAP::BOOSTER;
}

CBooster::CBooster(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CBooster::~CBooster()
{
}

int CBooster::Update_Map()
{
	return 0;
}

void CBooster::LateUpdate_Map()
{
}

void CBooster::Render_Map(HDC hDC)
{
}
