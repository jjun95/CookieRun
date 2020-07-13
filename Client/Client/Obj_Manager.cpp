#include "stdafx.h"
#include "Obj_Manager.h"
#include "Obj.h"

CObj_Manager* CObj_Manager::m_pInstance = nullptr;

CObj_Manager::CObj_Manager()
{
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

void CObj_Manager::Update_ObjectManager()
{
	// 최신 코드 ! 
	for (size_t i = 0; i < OBJ::OBJ_END; ++i)
	{
		auto& iter_end = m_listObject[i].end();
		for (auto& iter = m_listObject[i].begin(); iter != iter_end; )
		{
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
	CCollision_Manager::Collision_RectEX(m_listObject[OBJ::OBJ_MONSTER], m_listObject[OBJ::OBJ_PLAYER]);
	CCollision_Manager::Collision_Sphere(m_listObject[OBJ::OBJ_MONSTER], m_listObject[OBJ::OBJ_MOUSE]);
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
