#pragma once
#include "Maps.h"
class CBigCoin :
	public CMaps
{
public:
	explicit CBigCoin();
	explicit CBigCoin(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBigCoin();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
	
};

