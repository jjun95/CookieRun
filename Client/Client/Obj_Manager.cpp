#include "stdafx.h"
#include "Obj_Manager.h"
#include "Obj.h"
#include "Player.h"
#include "Pet.h"
#include "Maps.h"
#include "Map_Manager.h"

CObj_Manager* CObj_Manager::m_pInstance = nullptr;

CObj_Manager::CObj_Manager()
{
	m_plistMap[MAP::MAP_BLOCK] = CMap_Manager::Get_Instance()->Get_MapList(MAP::MAP_BLOCK);
	m_plistMap[MAP::MAP_COIN] = CMap_Manager::Get_Instance()->Get_MapList(MAP::MAP_COIN);
	m_plistMap[MAP::MAP_JELLY] = CMap_Manager::Get_Instance()->Get_MapList(MAP::MAP_JELLY);
	m_plistMap[MAP::MAP_OBSTACLE] = CMap_Manager::Get_Instance()->Get_MapList(MAP::MAP_OBSTACLE);
	m_plistMap[MAP::MAP_ITEM] = CMap_Manager::Get_Instance()->Get_MapList(MAP::MAP_ITEM);
}


CObj_Manager::~CObj_Manager()
{
	Release_ObjectManager();
}

CObj * CObj_Manager::Get_Target(CObj * pObj, OBJ::ID eTargetID)
{
	if (m_listObject[eTargetID].empty())
		return nullptr;

	CObj* pTarget = m_listObject[eTargetID].front(); 

	float fBaseX = pTarget->Get_Info()->fX - pObj->Get_Info()->fX; 
	float fBaseY = pTarget->Get_Info()->fY - pObj->Get_Info()->fY; 
	float fBaseDist = sqrt(fBaseX * fBaseX + fBaseY * fBaseY);

	for (auto& iter : m_listObject[eTargetID])
	{
		float fX1 = iter->Get_Info()->fX - pObj->Get_Info()->fX; 
		float fY1 = iter->Get_Info()->fY - pObj->Get_Info()->fY; 
		float fDist1 = sqrt(fX1 * fX1 + fY1 * fY1); 

		if (fDist1 < fBaseDist)
		{
			pTarget = iter; 
			fBaseDist = fDist1;
		}
	}

	return pTarget; 
}

void CObj_Manager::Add_Object(CObj * pObj, OBJ::ID eID)
{
	m_listObject[eID].emplace_back(pObj);
}

void CObj_Manager::Delete_Object(OBJ::ID eID)
{
	for (auto& iter = m_listObject[eID].begin(); iter != m_listObject[eID].end(); ) {
		iter = m_listObject[eID].erase(iter);
	}
}

void CObj_Manager::Update_ObjectManager()
{
	// �ֽ� �ڵ� ! 
	for (size_t i = 0; i < OBJ::OBJ_END; ++i)
	{
		auto& iter_end = m_listObject[i].end();
		for (auto& iter = m_listObject[i].begin(); iter != iter_end; )
		{
			if (m_listObject[i].empty())
				break;
			int iEvent = (*iter)->Update_Object();
			if (OBJ_DEAD == iEvent)
			{
				Safe_Delete(*iter);
				iter = m_listObject[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CObj_Manager::LateUpdate_ObjectManager()
{
	for (int i = 0; i < OBJ::OBJ_END; ++i)
	{
		for (auto& pObj : m_listObject[i])
		{
			pObj->LateUpdate_Object();
		}
	}
	if(CCollision_Manager::Collision_RectEX(*m_plistMap[MAP::MAP_BLOCK], m_listObject[OBJ::OBJ_PLAYER]))
		dynamic_cast<CPlayer*>(m_listObject[OBJ::OBJ_PLAYER].front())->Stop_Jump();
	CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_COIN], m_listObject[OBJ::OBJ_PLAYER]);
	CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_JELLY], m_listObject[OBJ::OBJ_PLAYER]);
	CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_ITEM], m_listObject[OBJ::OBJ_PLAYER]);
	if (dynamic_cast<CPet*>(m_listObject[OBJ::OBJ_PET].front())->Get_IsMagnet()) {
		CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_COIN], m_listObject[OBJ::OBJ_PET]);
		CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_JELLY], m_listObject[OBJ::OBJ_PET]);
		CCollision_Manager::Collision_ScoreRect(*m_plistMap[MAP::MAP_ITEM], m_listObject[OBJ::OBJ_PET]);
	}	
	if (!dynamic_cast<CPlayer*>(m_listObject[OBJ::OBJ_PLAYER].front())->Get_isInvincible())
		CCollision_Manager::Collision_ObstacleRect(*m_plistMap[MAP::MAP_OBSTACLE], m_listObject[OBJ::OBJ_PLAYER]);
}

void CObj_Manager::Render_ObjectManager(HDC hDC)
{
	for (int i = 0; i < OBJ::OBJ_END; ++i)
	{
		for (auto& pObj : m_listObject[i])
		{
			pObj->Render_Object(hDC);
		}
	}
}

void CObj_Manager::Release_ObjectManager()
{
	for (int i = 0; i < OBJ::OBJ_END; ++i)
	{
		for (auto& pObj : m_listObject[i])
			Safe_Delete(pObj);
		m_listObject[i].clear();
	}
}
