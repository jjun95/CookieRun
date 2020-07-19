#pragma once
#include "Scene.h"
class CStage :
	public CScene
{
public:
	CStage();
	virtual ~CStage();

	// CScene을(를) 통해 상속됨
	virtual void Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void LateUpdate_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;
};

