#pragma once
#include "Maps.h"
class CMiddleJelly :
	public CMaps
{
public:
	explicit CMiddleJelly();
	explicit CMiddleJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMiddleJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

