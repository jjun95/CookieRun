#pragma once
#include "Maps.h"
class CSmallHp :
	public CMaps
{
public:
	explicit CSmallHp();
	explicit CSmallHp(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CSmallHp();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};
