#pragma once
#include "Maps.h"
class CGiant :
	public CMaps
{
public:
	explicit CGiant();
	explicit CGiant(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CGiant();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

