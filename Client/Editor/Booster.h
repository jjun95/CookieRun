#pragma once
#include "Maps.h"
class CBooster :
	public CMaps
{
public:
	explicit CBooster();
	explicit CBooster(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBooster();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

