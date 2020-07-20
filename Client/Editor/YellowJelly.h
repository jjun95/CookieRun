#pragma once
#include "Maps.h"
class CYellowJelly :
	public CMaps
{
public:
	explicit CYellowJelly();
	explicit CYellowJelly(MAPINFO& mapInfo);
	virtual ~CYellowJelly();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

