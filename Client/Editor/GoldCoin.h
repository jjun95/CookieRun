#pragma once
#include "Maps.h"
class CGoldCoin :
	public CMaps
{
public:
	explicit CGoldCoin();
	explicit CGoldCoin(MAPINFO& mapInfo);
	virtual ~CGoldCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

