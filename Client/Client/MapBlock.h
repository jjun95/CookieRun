#pragma once
#include "Maps.h"
class CMapBlock : public CMaps
{
public:
	explicit CMapBlock();
	explicit CMapBlock(MAPINFO& mapInfo);
	~CMapBlock();

public:
	virtual void Update_Map();
	virtual void LateUpdate_Map();
	virtual void Render_Map(HDC hDC);
};