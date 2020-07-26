#include "stdafx.h"
#include "Map_Manager.h"
#include "MapBlock.h"
#include "Collision_Manager.h"
#include "BigCoin.h"
#include "SilverCoin.h"
#include "GoldCoin.h"
#include "BaseJelly.h"
#include "YellowJelly.h"
#include "PinkJelly.h"
#include "MiddleJelly.h"
#include "BigJelly.h"
#include "Obstacle1.h"
#include "Obstacle2.h"
#include "Obstacle3.h"
#include "Obstacle4.h"
#include "BigHp.h"
#include "SmallHp.h"
#include "Booster.h"
#include "Giant.h"
#include "Magnet.h"

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
	MAP::DETAILED_ID eDTID;
	while (true)
	{
		ReadFile(hFile, &tMapInfo, sizeof(MAPINFO), &dwByte, nullptr);
		ReadFile(hFile, &eDTID, sizeof(int), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		switch (eDTID) {
		case MAP::BLOCK:
			pMap = new CMapBlock(tMapInfo, eDTID);
			m_listMap[MAP::MAP_BLOCK].emplace_back(pMap);
			break;
		case MAP::SVCOIN:
			pMap = new CSilverCoin(tMapInfo, eDTID);
			m_listMap[MAP::MAP_COIN].emplace_back(pMap);
			break;
		case MAP::GDCOIN:
			pMap = new CGoldCoin(tMapInfo, eDTID);
			m_listMap[MAP::MAP_COIN].emplace_back(pMap);
			break;
		case MAP::BIGCOIN:
			pMap = new CBigCoin(tMapInfo, eDTID);
			m_listMap[MAP::MAP_COIN].emplace_back(pMap);
			break;
		case MAP::BASEJL:
			pMap = new CBaseJelly(tMapInfo, eDTID);
			m_listMap[MAP::MAP_JELLY].emplace_back(pMap);
			break;
		case MAP::PINKJL:
			pMap = new CPinkJelly(tMapInfo, eDTID);
			m_listMap[MAP::MAP_JELLY].emplace_back(pMap);
			break;
		case MAP::YELLOWJL:
			pMap = new CYellowJelly(tMapInfo, eDTID);
			m_listMap[MAP::MAP_JELLY].emplace_back(pMap);
			break;
		case MAP::MIDJL:
			pMap = new CMiddleJelly(tMapInfo, eDTID);
			m_listMap[MAP::MAP_JELLY].emplace_back(pMap);
			break;
		case MAP::BIGJL:
			pMap = new CBigJelly(tMapInfo, eDTID);
			m_listMap[MAP::MAP_JELLY].emplace_back(pMap);
			break;
		case MAP::OTC1:
			pMap = new CObstacle1(tMapInfo, eDTID);
			m_listMap[MAP::MAP_OBSTACLE].emplace_back(pMap);
			break;
		case MAP::OTC2:
			pMap = new CObstacle2(tMapInfo, eDTID);
			m_listMap[MAP::MAP_OBSTACLE].emplace_back(pMap);
			break;
		case MAP::OTC3:
			pMap = new CObstacle3(tMapInfo, eDTID);
			m_listMap[MAP::MAP_OBSTACLE].emplace_back(pMap);
			break;
		case MAP::OTC4:
			pMap = new CObstacle4(tMapInfo, eDTID);
			m_listMap[MAP::MAP_OBSTACLE].emplace_back(pMap);
			break;
		case MAP::BIGHP:
			pMap = new CBigHp(tMapInfo, eDTID);
			m_listMap[MAP::MAP_ITEM].emplace_back(pMap);
			break;
		case MAP::SMALLHP:
			pMap = new CSmallHp(tMapInfo, eDTID);
			m_listMap[MAP::MAP_ITEM].emplace_back(pMap);
			break;
		case MAP::BOOSTER:
			pMap = new CBooster(tMapInfo, eDTID);
			m_listMap[MAP::MAP_ITEM].emplace_back(pMap);
			break;
		case MAP::GIANT:
			pMap = new CGiant(tMapInfo, eDTID);
			m_listMap[MAP::MAP_ITEM].emplace_back(pMap);
			break;
		case MAP::MAGNET:
			pMap = new CMagnet(tMapInfo, eDTID);
			m_listMap[MAP::MAP_ITEM].emplace_back(pMap);
			break;
		}

	}
	MessageBox(nullptr, L"MapLoad ¼º°ø!", L"MapManager_Client", MB_OK);
	CloseHandle(hFile);
}

void CMap_Manager::Set_Pet(CObj * pPet)
{
	for (size_t i = MAP::MAP_COIN; i < MAP::MAP_END; ++i) {
		for (auto& pMapObject : m_listMap[i])
			pMapObject->Set_Pet(pPet);
	}
}

void CMap_Manager::Set_Speed(float speedInc)
{
	for (size_t i = 0; i < MAP::MAP_END; ++i) {
		for (auto& pMapObject : m_listMap[i])
		{
			pMapObject->Set_Speed(speedInc);
		}
	}
}

void CMap_Manager::Set_Magnet(bool isMagnet)
{
	for (size_t i = MAP::MAP_COIN; i < MAP::MAP_END; ++i) {
		for (auto& pMapObject : m_listMap[i])
			pMapObject->Set_Magnet(isMagnet);
	}
}

void CMap_Manager::Ready_MapManager()
{
	
}

void CMap_Manager::Update_MapManager()
{
	for (size_t i = 0; i < MAP::MAP_END; ++i)
	{
		auto& iter_end = m_listMap[i].end();
		for (auto& iter = m_listMap[i].begin(); iter != iter_end; ) {
			int iEvent = (*iter)->Update_Map();
			if (OBJ_DEAD == iEvent) {
				Safe_Delete(*iter);
				iter = m_listMap[i].erase(iter);
			}
			else ++iter;
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
			int mapLeft = pMapObject->Get_MapRect()->left + pMapObject->Get_Speed();
			if (mapLeft <= WINCX) 
				pMapObject->Render_Map(hDC);
			else break;
		}
	}
}

void CMap_Manager::Release_MapManager()
{
	for(size_t i = 0; i < MAP::MAP_END; ++i)
		for_each(m_listMap[i].begin(), m_listMap[i].end(), Safe_Delete<CMaps*>);
}
