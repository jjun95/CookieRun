#pragma once
#include "Maps.h"
class CYellowJelly :
	public CMaps
{
public:
	explicit CYellowJelly();
	explicit CYellowJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CYellowJelly();

	// CMaps을(를) 통해 상속됨
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

