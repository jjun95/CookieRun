#include "stdafx.h"
#include "Map_Manager.h"
#include "MapBlock.h"

CMap_Manager* CMap_Manager::m_pInstance = nullptr;

CMap_Manager::CMap_Manager()
{
}


CMap_Manager::~CMap_Manager()
{
	Release_MapManager();
}

void CMap_Manager::Load_MapData()
{

	HANDLE hFile = CreateFile(__T("../Data/Map.dat"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("LoadData Failed"), __T("MapManager_Client"), MB_OK);
		return;
	}
	CMaps* pMap = nullptr;
	DWORD dwByte = 0;
	MAPINFO tMapInfo = {};
	while (true)
	{
		ReadFile(hFile, &tMapInfo, sizeof(MAPINFO), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		pMap = new CMapBlock(tMapInfo);
		m_listMap.emplace_back(pMap);
	}
	MessageBox(nullptr, L"MapLoad ¼º°ø!", L"MapManager", MB_OK);
	CloseHandle(hFile);
}

bool CMap_Manager::MapCollision_MapManager(float fInX, float * pOutY)
{
	return false;
}

void CMap_Manager::Ready_MapManager()
{
	Load_MapData();
}

void CMap_Manager::Render_MapManager(HDC hDC)
{
	for (auto& pMapBlock : m_listMap)
	{
		pMapBlock->Render_Map(hDC);
	}
}

void CMap_Manager::Release_MapManager()
{
	for_each(m_listMap.begin(), m_listMap.end(), Safe_Delete<CMaps*>);
}
