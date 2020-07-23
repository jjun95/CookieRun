#pragma once
#include "Maps.h"
class CMapBlock : public CMaps
{
public:
	explicit CMapBlock();
	explicit CMapBlock(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMapBlock();

public:
	virtual void Render_Map(HDC hDC);
};