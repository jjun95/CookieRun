#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Obj.h"
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
	CMap_Manager::Get_Instance()->Render_MapManager(hDC);
	CObj_Manager::Get_Instance()->Render_ObjectManager(hDC);

	TCHAR szCoin[32] = L"";
	TCHAR szScore[32] = L"";
	TCHAR szHp[32] = L"";
	CObj* player = CObj_Manager::Get_Instance()->Get_Player();
	int coin = player->Get_CurCoin();
	int score = player->Get_CurScore();
	int hp = dynamic_cast<CPlayer*>(player)->Get_Hp();
	swprintf_s(szCoin, L"Coin : %d", coin);
	swprintf_s(szScore, L"score : %d", score);
	swprintf_s(szHp, L"hp : %d", hp);
	TextOut(hDC, 50, 80, szHp, lstrlen(szHp));
	TextOut(hDC, WINCX>>1, 20, szCoin, lstrlen(szCoin));
	TextOut(hDC, WINCX-200, 20, szScore, lstrlen(szScore));
}

void CStage::Release_Scene()
{
}
