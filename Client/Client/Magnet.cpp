#include "stdafx.h"
#include "Magnet.h"


CMagnet::CMagnet()
{
	m_tInfo = MAPINFO(MAGNET_CX, MAGNET_CY);
	m_eDTID = MAP::MAGNET;
}

CMagnet::CMagnet(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CMagnet::~CMagnet()
{
}

int CMagnet::Update_Map()
{
	return 0;
}

void CMagnet::LateUpdate_Map()
{
}

void CMagnet::Render_Map(HDC hDC)
{
}
