#pragma once
class CMyBitmap;

class CBitmap_Manager
{
public:
	static CBitmap_Manager* Get_Instance() {
		if (nullptr == m_pInstance)
			m_pInstance = new CBitmap_Manager();
		return m_pInstance;
	}
	static void Destroy_Instance() {
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	CBitmap_Manager();
	~CBitmap_Manager();

public:
	HDC Find_Image_BitmapManager(const TCHAR* pImageKey);
	void Insert_Texture_BitmapManager(const TCHAR* pFilePath, const TCHAR* pImageKey);
	void Release_BitmapManager();

private:
	static CBitmap_Manager* m_pInstance;
	map<const TCHAR*, CMyBitmap*> m_mapBmp;
};

