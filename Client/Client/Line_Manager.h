#pragma once
class CLine; 
class CLine_Manager
{
public:
	static CLine_Manager* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CLine_Manager; 
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
	CLine_Manager();
	~CLine_Manager();

public:
	void LoadData();
public:
	bool LineCollision_LineManager(float fInX, float* pOutY); 
public:
	void Ready_LineManager(); 
	void Render_LineManager(HDC hDC); 
	void Release_LineManager(); 


private:
	list<CLine*> m_listLine; 
	static CLine_Manager* m_pInstance; 
};

