#include "stdafx.h"
#include "BigHp.h"


CBigHp::CBigHp()
{
	m_tInfo = MAPINFO(BIGHP_CX, BIGHP_CY);
	m_eDTID = MAP::BIGHP;
}

CBigHp::CBigHp(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	:CMaps(mapInfo, eDTID)
{
}


CBigHp::~CBigHp()
{
}

int CBigHp::Update_Map()
{
	return 0;
}

void CBigHp::LateUpdate_Map()
{
}

void CBigHp::Render_Map(HDC hDC)
{
}
