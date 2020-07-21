#pragma once
#include "Maps.h"
class CBaseJelly :
	public CMaps
{
public:
	explicit CBaseJelly();
	explicit CBaseJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBaseJelly();

	// CMaps을(를) 통해 상속됨
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

