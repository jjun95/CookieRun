#include "stdafx.h"
#include "Map_Manager.h"
#include "Maps.h"
#include "MapBlock.h"
#include "Scroll_Manager.h"
#include "BigCoin.h"
#include "SilverCoin.h"
#include "GoldCoin.h"
#include "BaseJelly.h"
#include "YellowJelly.h"
#include "PinkJelly.h"
#include "Obstacle1.h"
#include "Obstacle2.h"
#include "Obstacle3.h"
#include "Obstacle4.h"1

CMap_Manager* CMap_Manager::m_pInstance = nullptr;

CMap_Manager::CMap_Manager()
{
}


CMap_Manager::~CMap_Manager()
{
	Release_MapManager();
}

void CMap_Manager::Save_MapData()
{

	HANDLE hFile = CreateFile(__T("../Data/Map.dat"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("SaveData Failed"), __T("MapManager_Editor"), MB_OK);
		return;
	}
	DWORD dwByte = 0;
	for (int i = 0; i < MAP::MAP_END; ++i) {
		for (auto& pMap : m_listMap[i])
		{
			WriteFile(hFile, pMap->Get_MapInfo(), sizeof(MAPINFO), &dwByte, nullptr);
		}
	}
	MessageBox(nullptr, L"MapSave 성공!", L"MapManager_Editor", MB_OK);
	CloseHandle(hFile);
}

void CMap_Manager::Load_MapData()
{

	HANDLE hFile = CreateFile(__T("../Data/Map.dat"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("LoadData Failed"), __T("MapManager_Editor"), MB_OK);
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
	MessageBox(nullptr, L"MapLoad 성공!", L"MapManager_Editor", MB_OK);
	CloseHandle(hFile);
}

void CMap_Manager::Ready_MapManager()
{
	
}

void CMap_Manager::Update_MapManager()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);

	pt.x -= CScroll_Manager::Get_ScrollX();

	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_BACKSPACE)) {
		if (!m_listMap[m_mapID].empty()) {
			auto& iter = m_listMap[m_mapID].end();
			--iter;
			Safe_Delete(*iter);
			iter = m_listMap[m_mapID].erase(iter);
		}
	}
	if (CKey_Manager::Get_Instance()->Key_Pressing(KEY_LEFT))
		CScroll_Manager::Set_ScrollX(-5);
	if (CKey_Manager::Get_Instance()->Key_Pressing(KEY_RIGHT))
		CScroll_Manager::Set_ScrollX(+5);
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_C)) {
		m_mapID = MAP::MAP_COIN;
		m_iMapKey = 1;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_J)) {
		m_mapID = MAP::MAP_JELLY;
		m_iMapKey = 1;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_O)) {
		m_mapID = MAP::MAP_OBSTACLE;
		m_iMapKey = 1;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_B)) {
		m_mapID = MAP::MAP_BLOCK;
		m_iMapKey = 1;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_1)) {
		m_iMapKey = 1;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_2)) {
		m_iMapKey = 2;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_3)) {
		m_iMapKey = 3;
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_4)) {
		m_iMapKey = 4;
	}

	if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON))
	{
		switch (m_mapID) {
		case MAP::MAP_BLOCK :
			m_pMap = new CMapBlock();
			break;
		case MAP::MAP_COIN:
			if(m_iMapKey == 1)
				m_pMap = new CSilverCoin();
			if (m_iMapKey == 2)
				m_pMap = new CGoldCoin();
			if (m_iMapKey == 3)
				m_pMap = new CBigCoin();
			break;
		case MAP::MAP_JELLY:
			if (m_iMapKey == 1)
				m_pMap = new CBaseJelly();
			if (m_iMapKey == 2)
				m_pMap = new CYellowJelly();
			if (m_iMapKey == 3)
				m_pMap = new CPinkJelly();
			break;
		case MAP::MAP_OBSTACLE:
			if (m_iMapKey == 1)
				m_pMap = new CObstacle1();
			if (m_iMapKey == 2)
				m_pMap = new CObstacle2();
			if (m_iMapKey == 3)
				m_pMap = new CObstacle3();
			if (m_iMapKey == 4)
				m_pMap = new CObstacle4();
			break;
		default:
			m_pMap = new CMapBlock();
			m_mapID = MAP::MAP_BLOCK;
			m_iMapKey = 1;
			break;
		}

		if (m_pMap != nullptr) {
			m_listMap[m_mapID].emplace_back(m_pMap);
			m_listMap[m_mapID].back()->Set_Pos(float(pt.x), float(pt.y));
		}
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_S))
		Save_MapData();
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_L))
		Load_MapData();
}

void CMap_Manager::Render_MapManager(HDC hDC)
{
	for (int i = 0; i < MAP::MAP_END; ++i) {
		for (auto& pMapBlock : m_listMap[i])
		{
			pMapBlock->Render_Map(hDC);
		}
	}
}

void CMap_Manager::Release_MapManager()
{
	for (int i = 0; i < MAP::MAP_END; ++i) {
		for_each(m_listMap[i].begin(), m_listMap[i].end(), Safe_Delete<CMaps*>);
	}
}
