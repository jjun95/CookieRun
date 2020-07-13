#pragma once
#include "Obj.h"
class CShield final :
	public CObj
{
public:
	explicit CShield();
	virtual ~CShield();
public:
	void Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
public:
	// CObj을(를) 통해 상속됨
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;

private:
	CObj* m_pTarget =nullptr; 
	float m_fDist = 0.f;
};

