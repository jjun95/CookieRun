#pragma once
#include "Maps.h"
class CPinkJelly :
	public CMaps
{
public:
	explicit CPinkJelly();
	explicit CPinkJelly(MAPINFO& mapInfo);
	virtual ~CPinkJelly();

	// CMaps��(��) ���� ��ӵ�
	virtual void Render_Map(HDC hDC) override;
};

