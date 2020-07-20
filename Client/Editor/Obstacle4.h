#pragma once
#include "Maps.h"
class CObstacle4 :
	public CMaps
{
public:
	explicit CObstacle4();
	explicit CObstacle4(MAPINFO& mapInfo);
	virtual ~CObstacle4();

	// CObstacle을(를) 통해 상속됨
	virtual void Render_Map(HDC hDC) override;
};

