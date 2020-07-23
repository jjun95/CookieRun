#pragma once
#include "Maps.h"
class CMiddleJelly :
	public CMaps
{
public:
	explicit CMiddleJelly();
	explicit CMiddleJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMiddleJelly();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

