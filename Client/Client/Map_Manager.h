#pragma once

class CMapBlock;

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

	bool MapCollision_MapManager(float fInX, float* pOutY);

public:
	void Ready_MapManager();
	void Render_MapManager(HDC hDC);
	void Release_MapManager();

private:
	list<CMapBlock*> m_listMap;
	static CMap_Manager* m_pInstance;
};

