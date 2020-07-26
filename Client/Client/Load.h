#pragma once
#include "Scene.h"
class CLoad :
	public CScene
{
public:
	explicit CLoad();
	explicit CLoad(CObj* pPlayer);
	virtual ~CLoad();

	// CScene��(��) ���� ��ӵ�
	virtual void Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void LateUpdate_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;

private:
	DWORD m_dwTime = 0;
};

