#include "stdafx.h"
#include "Giant.h"


CGiant::CGiant()
{
	m_tInfo = MAPINFO(GIANT_CX, GIANT_CY);
	m_eDTID = MAP::GIANT;
}

CGiant::CGiant(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CGiant::~CGiant()
{
}

int CGiant::Update_Map()
{
	return 0;
}

void CGiant::LateUpdate_Map()
{
}

void CGiant::Render_Map(HDC hDC)
{
}
