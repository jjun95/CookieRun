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
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object()			override;
	virtual int  Update_Object()		override;
	virtual void LateUpdate_Object()	override;
	virtual void Render_Object(HDC hDC)	override;
	virtual void Release_Object()		override;
	
private:
	float m_fDist = 0.f; 
	POINT m_tPosin; 

	bool m_bIsJump = false;
	float m_fJumpPower = 0.f; 
	float m_fJumpAccel = 0.f; 
};

// y = �� * sin@ * �ð� - 1/2 * �߷� * �ð� * �ð� 