#include "stdafx.h"
#include "Scene_Manager.h"
#include "Stage.h"
#include "Standby.h"
#include "Load.h"
#include "Result.h"

CScene_Manager* CScene_Manager::m_pInstance = nullptr;
CScene_Manager::CScene_Manager()
{
}


CScene_Manager::~CScene_Manager()
{
	Release_SCeneManager();
}

void CScene_Manager::Scene_Change_SceneManager(ID eSceneID, CObj* pPlayer)
{
	m_eNextScene = eSceneID;
	if (m_eCurScene != m_eNextScene) {
		Safe_Delete(m_pScene);
		switch (m_eNextScene) {
		case CScene_Manager::SCENE_LOAD:
			m_pScene = new CLoad(pPlayer);
			break;
		case CScene_Manager::SCENE_STANDBY:
			m_pScene = new CStandby(pPlayer);
			break;
		case CScene_Manager::SCENE_PLAY:
			m_pScene = new CStage(pPlayer);
			break;
		case CScene_Manager::SCENE_RESULT:
			m_pScene = new CResult(pPlayer);
			break;
		case CScene_Manager::SCENE_END:
			break;
		default:
			break;
		}
		m_pScene->Ready_Scene();
		m_eCurScene = m_eNextScene;
	}
}

void CScene_Manager::Update_SceneManager()
{
	m_pScene->Update_Scene();
}

void CScene_Manager::LateUpdate_SceneManager()
{
	m_pScene->LateUpdate_Scene();
}

void CScene_Manager::Render_SceneManager(HDC hDC)
{
	m_pScene->Render_Scene(hDC);
}

void CScene_Manager::Release_SCeneManager()
{
	Safe_Delete(m_pScene);
}
