#pragma once
#include "Maps.h"
class CBigJelly :
	public CMaps
{
public:
	explicit CBigJelly();
	explicit CBigJelly(MAPINFO& mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CBigJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

