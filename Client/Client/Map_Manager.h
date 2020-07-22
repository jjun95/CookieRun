#pragma once
#include "Maps.h"
#include "Obj.h"

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

	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	void Set_Speed(float speedInc);
	list<CMaps*>* Get_MapList(MAP::ID mapID) { return &m_listMap[mapID]; }
public:
	void Ready_MapManager();
	void Update_MapManager();
	void Render_MapManager(HDC hDC);
	void Release_MapManager();

private:
	list<CMaps*> m_listMap[MAP::MAP_END];
	CObj* m_pPlayer;
	static CMap_Manager* m_pInstance;
	MAP::ID m_mapID = MAP::MAP_END;
	int m_iMapKey;
};

