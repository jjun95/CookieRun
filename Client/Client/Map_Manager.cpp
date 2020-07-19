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
		m_listMap[MAP::MAP_BLOCK].emplace_back(pMap);
	}
	MessageBox(nullptr, L"MapLoad 성공!", L"MapManager", MB_OK);
	CloseHandle(hFile);
}

bool CMap_Manager::GroundCollision_MapManager(float inX, float * pOutY, int iCY)
{
	CMaps* pTarget = nullptr;


	// 일단 MapBlock에 대한 충돌처리만.
	for (auto& pMap : m_listMap[MAP::MAP_BLOCK]) {
		MAPINFO* mapInfo = pMap->Get_MapInfo();
		float mapSpeed = pMap->Get_Speed();
		if ((inX > mapInfo->tPoint.fLeft + mapSpeed) && (inX <= mapInfo->tPoint.fLeft + mapInfo->tPoint.iCX + mapSpeed) &&(*pOutY + (iCY >> 1) >= mapInfo->tPoint.fTop)) {
			pTarget = pMap;
			break;
		}
	}
	if (nullptr == pTarget)
		return false;

	return true;
}

void CMap_Manager::Ready_MapManager()
{
	
}

void CMap_Manager::Update_MapManager()
{
	for (size_t i = 0; i < MAP::MAP_END; ++i)
	{
		auto& iter_end = m_listMap[i].end();
		for (auto& iter = m_listMap[i].begin(); iter != iter_end; ++iter) {
			(*iter)->Update_Map();
		}
		for (auto& iter = m_listMap[i].begin(); iter != iter_end; ++iter) {
			(*iter)->LateUpdate_Map();
		}
	}
}

void CMap_Manager::Render_MapManager(HDC hDC)
{
	for (size_t i = 0; i < MAP::MAP_END; ++i) {
		for (auto& pMapObject : m_listMap[i])
		{
			pMapObject->Render_Map(hDC);
		}
	}
}

void CMap_Manager::Release_MapManager()
{
	for(size_t i = 0; i < MAP::MAP_END; ++i)
		for_each(m_listMap[i].begin(), m_listMap[i].end(), Safe_Delete<CMaps*>);
}
