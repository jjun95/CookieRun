#pragma once
#include "Maps.h"

class CMap_Manager
{
public:
	static CMap_Manager* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CMap_Manager;
		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	CMap_Manager();
	~CMap_Manager();

public:
	void Load_MapData();

	bool GroundCollision_MapManager(float inX, float * pOutY, int iCY);

public:
	void Ready_MapManager();
	void Update_MapManager();
	void Render_MapManager(HDC hDC);
	void Release_MapManager();

private:
	list<CMaps*> m_listMap[MAP::MAP_END];
	static CMap_Manager* m_pInstance;
};

