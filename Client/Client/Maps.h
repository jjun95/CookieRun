#pragma once
class CMaps abstract
{
public:
	explicit CMaps();
	explicit CMaps(MAPINFO & mapInfo);
	virtual ~CMaps();

public:
	MAPINFO* Get_MapInfo() { return &m_tInfo; }
	RECT* Get_MapRect() { return &m_tRect; }
	float Get_Speed() { return m_fSpeed; }
	void Set_Pos(const float fX, const float fY) {
		m_tInfo.tPoint.SetPosition(fX, fY);
	}
public:
	virtual void Update_Map() = 0;
	virtual void LateUpdate_Map() = 0;
	virtual void Render_Map(HDC hDC) = 0;

	void Update_Rect_Object();
protected:
	MAPINFO m_tInfo;
	RECT m_tRect;
	DWORD m_dwTime = 0;
	float m_fSpeed = 0.f;
	bool m_bIsDead = false;
};

