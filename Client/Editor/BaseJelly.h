#pragma once
#include "Maps.h"
class CBaseJelly :
	public CMaps
{
public:
	explicit CBaseJelly();
	explicit CBaseJelly(MAPINFO& mapInfo);
	virtual ~CBaseJelly();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

