#pragma once
#include "Maps.h"
class CObstacle3 :
	public CMaps
{
public:
	explicit CObstacle3();
	explicit CObstacle3(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CObstacle3();

	// CObstacle��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

