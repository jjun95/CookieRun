#pragma once
#include "Maps.h"
class CObstacle4 :
	public CMaps
{
public:
	explicit CObstacle4();
	explicit CObstacle4(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CObstacle4();

	// CObstacle��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

