#pragma once
#include "Maps.h"
class CBooster :
	public CMaps
{
public:
	explicit CBooster();
	explicit CBooster(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBooster();

	// CMaps��(��) ���� ��ӵ�
	virtual int Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};
