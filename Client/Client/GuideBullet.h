#pragma once
#include "Obj.h"
class CGuideBullet final:
	public CObj
{
public:
	explicit CGuideBullet();
	virtual ~CGuideBullet();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;

private:
	CObj* m_pTarget = nullptr; 

};

