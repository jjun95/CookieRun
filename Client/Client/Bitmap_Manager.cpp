#include "stdafx.h"
#include "Bitmap_Manager.h"
#include "MyBitmap.h"

CBitmap_Manager* CBitmap_Manager::m_pInstance = nullptr;

CBitmap_Manager::CBitmap_Manager()
{
}


CBitmap_Manager::~CBitmap_Manager()
{
	Release_BitmapManager();
}

HDC CBitmap_Manager::Find_Image_BitmapManager(const TCHAR * pImageKey)
{
	auto iter_find = m_mapBmp.find(pImageKey);
	if (iter_find == m_mapBmp.end())
		return nullptr;
	return iter_find->second->Get_MemDC();
}

void CBitmap_Manager::Insert_Texture_BitmapManager(const TCHAR * pFilePath, const TCHAR * pImageKey)
{
	auto& iter_find = find_if(m_mapBmp.begin(), m_mapBmp.end(), [&](auto& rPair) {
		return !lstrcmp(pImageKey, rPair.first);
	});

	if (iter_find != m_mapBmp.end())
		return;

	CMyBitmap* pBitmap = new CMyBitmap();
	pBitmap->Load_Bitmap(pFilePath);
	m_mapBmp.emplace(pImageKey, pBitmap);
}

void CBitmap_Manager::Release_BitmapManager()
{
	for (auto& rPair : m_mapBmp) {
		Safe_Delete(rPair.second);
	}
	m_mapBmp.clear();
}
