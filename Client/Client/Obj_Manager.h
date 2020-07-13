#pragma once
class CObj; 
class CObj_Manager
{
public:
	static CObj_Manager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CObj_Manager;

		return m_pInstance; 
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance; 
			m_pInstance = nullptr; 
		}
	}
private:
	CObj_Manager();
	~CObj_Manager();
public:
	CObj* Get_Player() { return m_listObject[OBJ::OBJ_PLAYER].front(); }
	CObj* Get_Target(CObj* pObj, OBJ::ID eTargetID); 
public:
	void Add_Object(CObj* pObj, OBJ::ID eID); 

public:
	void Update_ObjectManager();
	void LateUpdate_ObjectManager(); 
	void Render_ObjectManager(HDC hDC); 
	void Release_ObjectManager(); 
private:
	static CObj_Manager* m_pInstance;
private:
	list<CObj*> m_listObject[OBJ::OBJ_END];
};

