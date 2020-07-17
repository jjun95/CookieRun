#pragma once
#include "Maps.h"
class CMapBlock : public CMaps
{
public:
	explicit CMapBlock();
	explicit CMapBlock(MAPINFO& mapInfo);
	~CMapBlock();

public:
	void Update_Map();
	void Render_Map(HDC hDC);
};