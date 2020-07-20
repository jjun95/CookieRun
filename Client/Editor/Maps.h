#pragma once
#include "Scroll_Manager.h"
#include "Bitmap_Manager.h"

class CMaps abstract
{
public:
	explicit CMaps();
	explicit CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMaps();

public:
	MAPINFO* Get_MapInfo() { return &m_tInfo; }
	MAP::DETAILED_ID* Get_DTID() { return &m_eDTID; }
	void Set_Pos(const float fX, const float fY) {
		m_tInfo.tPoint.SetPosition(fX, fY);
	}
public:
	virtual void Render_Map(HDC hDC) = 0;
protected:
	MAPINFO m_tInfo;
	bool m_bIsDead = false;
	MAP::DETAILED_ID m_eDTID;
};

