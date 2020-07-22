#pragma once
#include "Obj.h"
class CPet :
	public CObj
{
public:
	explicit CPet();
	virtual ~CPet();

	// CObj��(��) ���� ��ӵ�
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;

private:
	CObj* m_pPlayer;

	OBJ::PET m_eCurState;
	OBJ::PET m_eNextState;
};

