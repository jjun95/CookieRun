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
		m_eNextState = OBJ::PLAYER_PAIN;
		m_dwHitTime = GetTickCount();
		CMap_Manager::Get_Instance()->Set_Speed(3.5f);
	}
	void Set_Hp(int plusHp) { m_iHp += plusHp; }
	int Get_Hp() { return m_iHp; }
	bool Get_isHit() { return m_bIsHit; }
	bool Get_IsJump() { return m_bIsJump; }
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
	float m_fTime = 0.f;
	float m_fHeight = 0.f;
	float m_fStartHeight = 0.f;
	DWORD m_dwJumpTime;
	
	DWORD m_dwHitTime = 0;
	bool m_bIsHit = false;
	bool blink = false;

	TCHAR* m_szFrameKey;
	OBJ::STATE m_eCurState;
	OBJ::STATE m_eNextState;

	int m_iHp;
	int m_iMaxHp;
};