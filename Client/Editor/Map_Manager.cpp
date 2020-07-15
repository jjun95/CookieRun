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

void CMap_Manager::Save_MapData()
{

	HANDLE hFile = CreateFile(__T("../Data/Map.dat"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("SaveData Failed"), __T("MapManager"), MB_OK);
		return;
	}
	DWORD dwByte = 0;
	for (auto& pMapBlock : m_listMap)
	{
		WriteFile(hFile, pMapBlock->Get_MapInfo(), sizeof(MAPINFO), &dwByte, nullptr);
	}
	MessageBox(nullptr, L"MapSave 성공!", L"맵매니저!", MB_OK);
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

	if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON))
	{
		CMapBlock* pMapBlock = new CMapBlock(MAPINFO());
		m_listMap.emplace_back(pMapBlock);
		m_listMap.back()->Set_Pos(MAPPOS(float(pt.x), float(pt.y)));
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_S))
	{
		Save_MapData();
	}
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
	for_each(m_listMap.begin(), m_listMap.end(), Safe_Delete<CMapBlock*>);
}
