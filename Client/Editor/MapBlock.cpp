#include "stdafx.h"
#include "MapBlock.h"


CMapBlock::CMapBlock()
{
}

CMapBlock::CMapBlock(const MAPINFO & mapInfo)
	: m_tInfo(mapInfo)
{
}


CMapBlock::~CMapBlock()
{
}

void CMapBlock::Render_Map(HDC hDC)
{
	Rectangle(hDC, m_tInfo.tPoint.fX - 45, m_tInfo.tPoint.fY - 45, m_tInfo.tPoint.fX + 45, m_tInfo.tPoint.fY + 45);
}
