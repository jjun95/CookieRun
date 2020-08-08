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
	static void Set_BestScore(int score) { m_iBestScore = score; }
	static void Set_MyCoin(int coin) { m_iMyCoin += coin; }
	void Set_Coin(int coin, bool setZero = false) { 
		if (setZero)
			m_iCoin = 0;
		else m_iCoin += coin; 
	}
	void Set_Score(int score, bool setZero = false) { 
		if (setZero)
			m_iScore = 0;
		else m_iScore += score; 
	}
	static void HP_LevelUp() { m_iHpLevel++; }
	static void Jelly_LevelUp() { m_iJellyLevel++; }

	int Get_CurCoin() { return m_iCoin; }
	int Get_CurScore() { return m_iScore; }
	static int Get_TotalCoin() { return m_iMyCoin; }
	static int Get_BestScore() { return m_iBestScore; }
	static int Get_HpLevel() { return m_iHpLevel; }
	static int Get_JellyLevel() { return m_iJellyLevel; }

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

	static int m_iBestScore;
	static int m_iMyCoin;
	int m_iScore = 0;
	int m_iCoin = 0;
	static int m_iHpLevel;
	static int m_iJellyLevel;
};

