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
	Rectangle(hDC, m_tInfo.tPoint.fLeft , m_tInfo.tPoint.fTop, m_tInfo.tPoint.fLeft + MAPTILE_SIZE, m_tInfo.tPoint.fTop + MAPTILE_SIZE);
}
