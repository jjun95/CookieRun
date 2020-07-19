#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Map_Manager.h"
#include "Obj_Manager.h"


CStage::CStage()
{
}


CStage::~CStage()
{
}

void CStage::Ready_Scene()
{
	CObj* pObj = CAbstractFactory<CPlayer>::Create();
	CObj_Manager::Get_Instance()->Add_Object(pObj, OBJ::OBJ_PLAYER);

	CMap_Manager::Get_Instance()->Load_MapData();
}

void CStage::Update_Scene()
{
	CObj_Manager::Get_Instance()->Update_ObjectManager();
	CMap_Manager::Get_Instance()->Update_MapManager();
}

void CStage::LateUpdate_Scene()
{
	CObj_Manager::Get_Instance()->LateUpdate_ObjectManager();
}

void CStage::Render_Scene(HDC hDC)
{
	CObj_Manager::Get_Instance()->Render_ObjectManager(hDC);
	CMap_Manager::Get_Instance()->Render_MapManager(hDC);
}

void CStage::Release_Scene()
{
}
