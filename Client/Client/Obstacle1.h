#pragma once
#include "Maps.h"
class CObstacle1 :
	public CMaps
{
public:
	explicit CObstacle1();
	explicit CObstacle1(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CObstacle1();

	// CObstacle��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
	virtual void Update_Map() override;
	virtual void LateUpdate_Map() override;
};

