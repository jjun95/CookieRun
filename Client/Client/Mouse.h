#pragma once
#include "Obj.h"
class CMouse final :
	public CObj
{
public:
	explicit CMouse();
	virtual ~CMouse();
public:
	// CObj을(를) 통해 상속됨
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;
};

