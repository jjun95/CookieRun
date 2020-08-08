#pragma once
#include "Obj.h"
#include "Map_Manager.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	void KeyCheck(); 
	bool IsJumping(); 
	void Animation_Change();
	void Stop_Jump();

	void Set_Hit() { 
		m_bIsHit = true; 
		m_bIsInvincible = true;
		m_eNextState = OBJ::PLAYER_PAIN;
		m_dwHitTime = GetTickCount();
		m_dwInvincibleTime = GetTickCount();
		CMap_Manager::Get_Instance()->Set_Speed(DEFAULT_SPEED / 2);
	}
	void Set_Dead() {
		if (!m_bIsDead)
			m_dwEndTime = GetTickCount();
		m_iHp = 0;
		m_eNextState = OBJ::PLAYER_DIE;
		m_bIsDead = true;
		m_bIsInvincible = true;
		CMap_Manager::Get_Instance()->Set_Speed(0);
	}
	void Set_Hp(int plusHp, bool setMax = false) {
		if (setMax) {
			m_bIsDead = false;
			m_iMaxHp = 150 + 10 * m_iHpLevel;
			m_iHp = m_iMaxHp;
			m_eNextState = OBJ::PLAYER_RUN;
		}
		else m_iHp += plusHp;
	}
	void Set_MaxHp() { m_iMaxHp += 10; m_iHp = m_iMaxHp; }
	void Set_IsBoost() { m_bIsBoost = true; m_dwRushTime = GetTickCount(); m_eNextState = OBJ::PLAYER_RUSH;}
	void Set_IsGiant() { m_bIsGiant = true; m_dwGiantTime = GetTickCount(); }
	void Set_IsInvincible() { m_bIsInvincible = true; }
	int Get_Hp() { return m_iHp; }
	int Get_MaxHp() { return m_iMaxHp; }
	bool Get_isInvincible() { return m_bIsInvincible; }
	bool Get_IsJump() { return m_bIsJump; }
	bool Get_IsBoost() { return m_bIsBoost; }
	bool Get_IsGiant() { return m_bIsGiant; }
public:
	// CObj을(를) 통해 상속됨
	virtual void Ready_Object()			override;
	virtual int  Update_Object()		override;
	virtual void LateUpdate_Object()	override;
	virtual void Render_Object(HDC hDC)	override;
	virtual void Release_Object()		override;
private:
	bool m_bIsJump = false;
	bool m_bIsDoubleJump = false;
	bool m_bIsHit = false;
	bool m_bIsblink = false;
	bool m_bIsBoost = false;
	bool m_bIsGiant = false;
	bool m_bIsInvincible = false;
	int m_iHp;
	int m_iMaxHp;
	float m_fTime = 0.f;
	float m_fHeight = 0.f;
	float m_fStartHeight = 0.f;
	TCHAR* m_szFrameKey;
	OBJ::PLAYER m_eCurState;
	OBJ::PLAYER m_eNextState;
	DWORD m_dwJumpTime;	
	DWORD m_dwHitTime = 0;
	DWORD m_dwRunTime = 0;
	DWORD m_dwRushTime = 0;
	DWORD m_dwGiantTime = 0;
	DWORD m_dwInvincibleTime = 0;
	DWORD m_dwEndTime = 0;
};