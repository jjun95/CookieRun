#pragma once
#include "Bitmap_Manager.h"

class CObj;

class CMaps abstract
{
public:
	explicit CMaps();
	explicit CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID);
	explicit CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID, CObj* pPet);
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
	MAP::DETAILED_ID Get_DTID() { return m_eDTID; }

	void Set_Pet(CObj* pPet) { m_pPet = pPet; }
	void Set_Magnet(bool isMagnet) { m_bIsMagnet = isMagnet; }
	void Set_Speed(float speedInc) { m_fSpeedInc = speedInc; }
	void Set_Dead() { m_bIsDead = true; }
	void Set_Pos(const float fX, const float fY) {
		m_tInfo.tPoint.SetPosition(fX, fY);
	}
public:
	virtual int Update_Map();
	virtual void LateUpdate_Map();
	virtual void Render_Map(HDC hDC) = 0;

	void Update_Rect_Object();
	virtual void MoveFrame();
protected:
	bool m_bIsDead = false;
	bool m_bIsMagnet = false;
	MAPINFO m_tInfo;
	RECT m_tRect;
	DWORD m_dwTime = 0;
	float m_fSpeed = 0.f;
	float m_fSpeedInc = DEFAULT_SPEED;
	MAP::DETAILED_ID m_eDTID;
	FRAME m_tFrame;

	CObj* m_pPet = nullptr;
	int m_iCValue = 0; // 코인
	int m_iSValue = 0; // 점수
};

