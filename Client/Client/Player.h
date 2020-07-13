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
	// CObj을(를) 통해 상속됨
	virtual void Ready_Object()			override;
	virtual int  Update_Object()		override;
	virtual void LateUpdate_Object()	override;
	virtual void Render_Object(HDC hDC)	override;
	virtual void Release_Object()		override;
public:
// 	CObj* CreateBullet();
// 	CObj* CreateBullet(BULLET::ID eDir);
// 	CObj* CreateBullet(float fAngle );
// 	CObj* CreateScrewBullet();
// 	CObj* CreateGuideBullet(); 
	template<typename T> 
	CObj* CreateBullet()
	{
		CObj* pInstance = CAbstractFactory<T>::Create(float(m_tPosin.x), (float)m_tPosin.y, m_fAngle);
		return pInstance; 
	}
	CObj* CreateShield();
	
private:
	float m_fDist = 0.f; 
	POINT m_tPosin; 

	bool m_bIsJump = false;
	float m_fJumpPower = 0.f; 
	float m_fJumpAccel = 0.f; 
};

// y = 힘 * sin@ * 시간 - 1/2 * 중력 * 시간 * 시간 