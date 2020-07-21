#pragma once
#include "Maps.h"
class CSilverCoin :
	public CMaps
{
public:
	explicit CSilverCoin();
	explicit CSilverCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CSilverCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

