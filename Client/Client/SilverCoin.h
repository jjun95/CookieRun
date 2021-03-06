#pragma once
#include "Maps.h"
class CSilverCoin :
	public CMaps
{
public:
	explicit CSilverCoin();
	explicit CSilverCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CSilverCoin();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

