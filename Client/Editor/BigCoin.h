#pragma once
#include "Maps.h"
class CBigCoin :
	public CMaps
{
public:
	explicit CBigCoin();
	explicit CBigCoin(MAPINFO& mapInfo);
	virtual ~CBigCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

