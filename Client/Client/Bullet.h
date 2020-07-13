#pragma once
#include "Obj.h"
class CBullet final:
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();
public:
	void Set_Dir(BULLET::ID eDir) { m_eDir = eDir; }
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;
private:
	BULLET::ID m_eDir = BULLET::��; 
};

