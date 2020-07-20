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

void CMaps::Update_Rect_Object()
{
	m_tRect.left = LONG(m_tInfo.tPoint.fX - (m_tInfo.tPoint.iCX >> 1));
	m_tRect.top = LONG(m_tInfo.tPoint.fY - (m_tInfo.tPoint.iCY >> 1));
	m_tRect.right = LONG(m_tInfo.tPoint.fX + (m_tInfo.tPoint.iCX >> 1));
	m_tRect.bottom = LONG(m_tInfo.tPoint.fY + (m_tInfo.tPoint.iCY >> 1));
}
