#pragma once
#include "Maps.h"
class CMagnet :
	public CMaps
{
public:
	explicit CMagnet();
	explicit CMagnet(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMagnet();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

