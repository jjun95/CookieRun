#pragma once
#include "Obj.h"
class CScrewBullet final:
	public CObj
{
public:
	explicit CScrewBullet();
	virtual ~CScrewBullet();
public:
	// CObj을(를) 통해 상속됨
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;

private:
	bool m_bIsInit = true; 
	POINT m_tCenter = {};
	float m_fRevAngle = 0.f; 
	float m_fRevDist = 0.f; 
	float m_fRevSpeed =0.f; 
};

