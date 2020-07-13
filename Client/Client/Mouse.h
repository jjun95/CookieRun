#pragma once
#include "Obj.h"
class CMouse final :
	public CObj
{
public:
	explicit CMouse();
	virtual ~CMouse();
public:
	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;
};

