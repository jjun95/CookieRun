#pragma once
#include "Maps.h"
class CYellowJelly :
	public CMaps
{
public:
	explicit CYellowJelly();
	explicit CYellowJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CYellowJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

