#pragma once
#include "Maps.h"
class CBigCoin :
	public CMaps
{
public:
	explicit CBigCoin();
	explicit CBigCoin(MAPINFO& mapInfo);
	virtual ~CBigCoin();

	// CMaps을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

