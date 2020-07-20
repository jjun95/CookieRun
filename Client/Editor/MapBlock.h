#pragma once
#include "Maps.h"

class CMapBlock : public CMaps
{
public:
	explicit CMapBlock();
	explicit CMapBlock(MAPINFO& mapInfo);
	virtual ~CMapBlock();
public:
	virtual void Render_Map(HDC hDC);
};

