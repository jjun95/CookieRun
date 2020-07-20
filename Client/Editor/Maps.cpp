#include "stdafx.h"
#include "Maps.h"


CMaps::CMaps()
{
}

CMaps::CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: m_tInfo(mapInfo), m_eDTID(eDTID)
{
}

CMaps::~CMaps()
{
}
