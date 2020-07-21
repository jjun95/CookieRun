#pragma once
#include "Maps.h"
class CBigCoin :
	public CMaps
{
public:
	explicit CBigCoin();
	explicit CBigCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBigCoin();

	// CMaps을(를) 통해 상속됨
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
	
};

