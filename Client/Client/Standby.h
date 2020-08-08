#pragma once
#include "Scene.h"
class CStandby :
	public CScene
{
public:
	explicit CStandby();
	explicit CStandby(CObj* pPlayer);
	virtual ~CStandby();

	// CScene을(를) 통해 상속됨
	virtual void Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void LateUpdate_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;

private:
	RECT m_tHpRect;
	RECT m_tJellyRect;
	RECT m_tUpgradeRect;
	RECT m_tStartRect;
	int m_iClicked = 0;
	int m_iCoin;
	int m_iLevel;
	int m_iIsEnough = 0;
};

