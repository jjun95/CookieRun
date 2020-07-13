#pragma once
#include "Obj.h"
class CMonster final:
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();
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
	CObj* m_pTarget = nullptr; 

};

