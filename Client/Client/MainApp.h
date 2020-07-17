#pragma once
class CObj; 
class CObj_Manager;
class CMaps;
class CMainApp final 
{
public:
	CMainApp();
	~CMainApp();

public:
	void Ready_MainApp(); 
	void Update_MainApp(); 
	void LateUpdate_MainApp(); 
	void Render_MainApp(); 
	void Release_MainApp(); 

private:
	HDC m_hDC; 
// 	CObj* m_pPlayer = nullptr; 
// 	list<CObj*> m_listBullet; 
	
	CObj_Manager* m_pObj_Manager = nullptr; 
	int m_iFPS = 0;
	DWORD m_dwOldTime =0; 
	TCHAR m_szFPS[32] = L""; 
	list<CMaps*>* m_listMaps[MAP::MAP_END];

};

