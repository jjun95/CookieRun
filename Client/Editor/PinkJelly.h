#pragma once
#include "Maps.h"
class CPinkJelly :
	public CMaps
{
public:
	explicit CPinkJelly();
	explicit CPinkJelly(MAPINFO& mapInfo);
	virtual ~CPinkJelly();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

