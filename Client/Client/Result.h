#pragma once
#include "Scene.h"
class CResult :
	public CScene
{
public:
	explicit CResult();
	explicit CResult(CObj* pPlayer);
	virtual ~CResult();

	// CScene��(��) ���� ��ӵ�
	virtual void Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void LateUpdate_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;

private:
	RECT m_tOKRect;
};

