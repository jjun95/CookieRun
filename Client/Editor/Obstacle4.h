#pragma once
#include "Maps.h"
class CObstacle4 :
	public CMaps
{
public:
	explicit CObstacle4();
	explicit CObstacle4(MAPINFO& mapInfo);
	virtual ~CObstacle4();

	// CObstacle��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

