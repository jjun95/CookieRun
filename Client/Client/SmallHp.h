#pragma once
#include "Maps.h"
class CSmallHp :
	public CMaps
{
public:
	explicit CSmallHp();
	explicit CSmallHp(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CSmallHp();

	// CMaps을(를) 통해 상속됨;
	virtual void Render_Map(HDC hDC) override;
};

