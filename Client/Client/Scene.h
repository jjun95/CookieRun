#pragma once
class CScene abstract
{
public:
	explicit CScene();
	virtual ~CScene();

	virtual void Ready_Scene() = 0;
	virtual void Update_Scene() = 0;
	virtual void LateUpdate_Scene() = 0;
	virtual void Render_Scene(HDC hDC) = 0;
	virtual void Release_Scene() = 0;
};

