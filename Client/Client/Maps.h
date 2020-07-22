#pragma once
#include "Bitmap_Manager.h"

class CMaps abstract
{
public:
	explicit CMaps();
	explicit CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	virtual ~CMaps();

public:
	MAPINFO* Get_MapInfo() { return &m_tInfo; }
	RECT* Get_MapRect() {
		RECT tRect;
		tRect.left = m_tRect.left + m_fSpeed;
		tRect.right = m_tRect.right + m_fSpeed;
		tRect.top = m_tRect.top;
		tRect.bottom = m_tRect.bottom;
		return &tRect; 
	}
	float Get_Speed() { return m_fSpeed; }
	int Get_Coin() { return m_iCValue; }
	int Get_Score() { return m_iSValue; }

	void Set_Speed(float speedInc) { m_fSpeedInc = speedInc; }
	void Set_Dead() { m_bIsDead = true; }
	void Set_Pos(const float fX, const float fY) {
		m_tInfo.tPoint.SetPosition(fX, fY);
	}
public:
	virtual int Update_Map() = 0;
	virtual void LateUpdate_Map() = 0;
	virtual void Render_Map(HDC hDC) = 0;

	void Update_Rect_Object();
protected:
	MAPINFO m_tInfo;
	RECT m_tRect;
	DWORD m_dwTime = 0;
	float m_fSpeed = 0.f;
	float m_fSpeedInc = 5.f;
	bool m_bIsDead = false;
	MAP::DETAILED_ID m_eDTID;
	int m_iCValue = 0; // 코인
	int m_iSValue = 0; // 점수
};

