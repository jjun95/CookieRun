#pragma once
#include "Obj.h"
class CPet :
	public CObj
{
public:
	explicit CPet();
	virtual ~CPet();

	// CObj을(를) 통해 상속됨
	virtual void Ready_Object() override;
	virtual int Update_Object() override;
	virtual void LateUpdate_Object() override;
	virtual void Render_Object(HDC hDC) override;
	virtual void Release_Object() override;

	void Set_Magnet() { 
		m_bIsMagnet = true; 
		m_dwMagnetTime = GetTickCount();
		m_eNextState = OBJ::PET_MAGNET;
	}
	bool Get_IsMagnet() { return m_bIsMagnet; }

	void Animation_Change();

private:
	bool m_bIsMagnet = false;
	DWORD m_dwMagnetTime = 0;
	CObj* m_pPlayer;

	OBJ::PET m_eCurState;
	OBJ::PET m_eNextState;
};

