#pragma once
#include "Maps.h"
class CBigHp :
	public CMaps
{
public:
	explicit CBigHp();
	explicit CBigHp(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBigHp();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

