#pragma once
#include "Maps.h"
class CGoldCoin :
	public CMaps
{
public:
	explicit CGoldCoin();
	explicit CGoldCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CGoldCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

