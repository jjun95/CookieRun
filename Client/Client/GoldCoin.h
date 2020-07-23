#pragma once
#include "Maps.h"
class CGoldCoin :
	public CMaps
{
public:
	explicit CGoldCoin();
	explicit CGoldCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CGoldCoin();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

