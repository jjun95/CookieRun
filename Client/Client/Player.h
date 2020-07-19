#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	void KeyCheck(); 
	void IsJumping(); 
	void Animation_Change();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object()			override;
	virtual int  Update_Object()		override;
	virtual void LateUpdate_Object()	override;
	virtual void Render_Object(HDC hDC)	override;
	virtual void Release_Object()		override;
	
private:
	bool m_bIsJump = false;
	bool m_bIsDoubleJump = false;
	float m_fJumpPower = 0.f;
	float m_fJumpAccel = 0.f;
	float m_fStartfY = 0.f;
	DWORD m_dwJumpTime;

	TCHAR* m_szFrameKey;
	OBJ::STATE m_eCurState;
	OBJ::STATE m_eNextState;
};

// y = �� * sin@ * �ð� - 1/2 * �߷� * �ð� * �ð� 