#pragma once
#include "Maps.h"
class CBaseJelly :
	public CMaps
{
public:
	explicit CBaseJelly();
	explicit CBaseJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBaseJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

