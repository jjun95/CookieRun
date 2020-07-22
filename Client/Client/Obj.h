#pragma once
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();
public:
	void Set_Pos(float fX, float fY)
	{
		m_tInfo.fX = fX; 
		m_tInfo.fY = fY; 
	}
	//void Set_Angle(float fAngle) { m_fAngle = fAngle; }
	void Set_Dead() { m_bIsDead = true;  }
	void Set_BestScore(int score) { m_iBestScore = score; }
	void Set_MyCoin(int coin) { m_iMyCoin += coin; }
	void Set_Coin(int coin) { m_iCoin += coin; }
	void Set_Score(int score) { m_iScore += score; }

	int Get_CurCoin() { return m_iCoin; }
	int Get_CurScore() { return m_iScore; }
	int Get_TotalCoin() { return m_iMyCoin; }
	int Get_BestScore() { return m_iBestScore; }

	const RECT* Get_Rect() const { return &m_tRect;  }
	const INFO* Get_Info() const { return &m_tInfo; }

public:
	virtual void Ready_Object()			=0; 
	virtual int	 Update_Object()		=0; 
	virtual void LateUpdate_Object()	=0; 
	virtual void Render_Object(HDC hDC)	=0;
	virtual void Release_Object()		=0; 
public:
	void Update_Rect_Object(int left, int top, int right, int bottom); 
	void MoveFrame();
protected:
	RECT m_tRect; 
	INFO m_tInfo; 
	float m_fSpeed; 
	bool m_bIsDead = false; 
	//float m_fAngle = 0.f; 
	FRAME m_tFrame;

	int m_iBestScore = 0;
	int m_iMyCoin = 0;
	int m_iScore = 0;
	int m_iCoin = 0;
};

