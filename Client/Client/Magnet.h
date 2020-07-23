#pragma once
#include "Maps.h"
class CMagnet :
	public CMaps
{
public:
	explicit CMagnet();
	explicit CMagnet(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMagnet();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};
