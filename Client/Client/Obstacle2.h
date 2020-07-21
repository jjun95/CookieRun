#pragma once
#include "Maps.h"
class CObstacle2 :
	public CMaps
{
public:
	explicit CObstacle2();
	explicit CObstacle2(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CObstacle2();

	// CObstacle을(를) 통해 상속됨
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

