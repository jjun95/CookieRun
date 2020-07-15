#include "stdafx.h"
#include "MapBlock.h"


CMapBlock::CMapBlock()
{
}

CMapBlock::CMapBlock(const MAPINFO& mapInfo)
	: m_tInfo(mapInfo)
{
}

CMapBlock::~CMapBlock()
{
}

void CMapBlock::Render_Map(HDC hDC)
{
	Rectangle(hDC, m_tInfo.tPoint.fX + mapSize / 2, m_tInfo.tPoint.fY + mapSize * 0.5, m_tInfo.tPoint.fX + mapSize * 1.5, m_tInfo.tPoint.fY + mapSize * 1.5);
}