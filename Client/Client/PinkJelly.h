#pragma once
#include "Maps.h"
class CPinkJelly :
	public CMaps
{
public:
	explicit CPinkJelly();
	explicit CPinkJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CPinkJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Update_Map() override;
	virtual void LateUpdate_Map() override;
	virtual void Render_Map(HDC hDC) override;
};

