#pragma once

class CScene;
class CObj;

class CScene_Manager
{
public:
	static CScene_Manager* Get_Instance() {
		if (nullptr == m_pInstance)
			m_pInstance = new CScene_Manager();
		return m_pInstance;
	}
	static void Destroy_Instance() {
		if (nullptr != m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	 enum ID {SCENE_LOAD, SCENE_STANDBY, SCENE_PLAY, SCENE_RESULT, SCENE_END};
private:
	CScene_Manager();
	~CScene_Manager();
public:
	void Scene_Change_SceneManager(ID eSceneID, CObj* pPlayer);
	void Update_SceneManager();
	void LateUpdate_SceneManager();
	void Render_SceneManager(HDC hDC);
	void Release_SCeneManager();
private:
	static CScene_Manager* m_pInstance;
	CScene* m_pScene = nullptr;
	ID m_eCurScene = SCENE_END;
	ID m_eNextScene = SCENE_END;
};

