#pragma once
#include "Maps.h"

class CMapBlock : public CMaps
{
public:
	explicit CMapBlock();
	explicit CMapBlock(MAPINFO& mapInfo);
	~CMapBlock();
public:
	void Render_Map(HDC hDC);
};

