#pragma once
#include "Scroll_Manager.h"
#include "Bitmap_Manager.h"

class CMaps abstract
{
public:
	explicit CMaps();
	explicit CMaps(MAPINFO & mapInfo);
	virtual ~CMaps();

public:
	MAPINFO* Get_MapInfo() { return &m_tInfo; }
	void Set_Pos(const float fX, const float fY) {
		m_tInfo.tPoint.SetPosition(fX, fY);
	}
public:
	virtual void Render_Map(HDC hDC) = 0;
protected:
	MAPINFO m_tInfo;
};

