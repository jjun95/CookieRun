#pragma once
#include "Maps.h"
class CSilverCoin :
	public CMaps
{
public:
	explicit CSilverCoin();
	explicit CSilverCoin(MAPINFO& mapInfo);
	virtual ~CSilverCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

