#pragma once
#include "Obj.h"
class CScene abstract
{
public:
	explicit CScene();
	explicit CScene(CObj* pPlayer);
	virtual ~CScene();

	virtual void Ready_Scene() = 0;
	virtual void Update_Scene() = 0;
	virtual void LateUpdate_Scene() = 0;
	virtual void Render_Scene(HDC hDC) = 0;
	virtual void Release_Scene() = 0;

protected:
	CObj* m_pPlayer;
};

