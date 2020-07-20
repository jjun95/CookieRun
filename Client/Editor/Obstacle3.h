#pragma once
#include "Maps.h"
class CObstacle3 :
	public CMaps
{
public:
	explicit CObstacle3();
	explicit CObstacle3(MAPINFO& mapInfo);
	virtual ~CObstacle3();

	// CObstacle을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

