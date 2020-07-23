#pragma once
#include "Maps.h"
class CBigJelly :
	public CMaps
{
public:
	explicit CBigJelly();
	explicit CBigJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBigJelly();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

