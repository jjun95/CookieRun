#pragma once
#include "Maps.h"
class CObstacle1 :
	public CMaps
{
public:
	explicit CObstacle1();
	explicit CObstacle1(MAPINFO& mapInfo);
	virtual ~CObstacle1();

	// CObstacle��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

