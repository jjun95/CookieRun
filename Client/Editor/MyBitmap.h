#pragma once
class CMyBitmap
{
public:
	CMyBitmap();
	~CMyBitmap();
	
	HDC Get_MemDC() { return m_hMemDC; }
	void Load_Bitmap(const TCHAR* pFilePath);
	void Release_Bitmap();

private:
	HDC m_hMemDC;
	HBITMAP m_OldBitmap;
	HBITMAP m_hBitmap;
};

