#include "stdafx.h"
#include "MyBitmap.h"


CMyBitmap::CMyBitmap()
{
}


CMyBitmap::~CMyBitmap()
{
}

void CMyBitmap::Load_Bitmap(const TCHAR * pFilePath)
{
	HDC hDC = GetDC(g_hWND);

	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWND, hDC);

	m_hBitmap = (HBITMAP)LoadImage(nullptr, pFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_OldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CMyBitmap::Release_Bitmap()
{
	SelectObject(m_hMemDC, m_OldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}
