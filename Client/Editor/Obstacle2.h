#pragma once
#include "Maps.h"
class CObstacle2 :
	public CMaps
{
public:
	explicit CObstacle2();
	explicit CObstacle2(MAPINFO& mapInfo);
	virtual ~CObstacle2();

	// CObstacle��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

