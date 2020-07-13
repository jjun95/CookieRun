// TestClient.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//							0000 0001
const DWORD KEY_LBUTTON =	0x00000001; 
//							0000 0010
#define		KEY_RBUTTON		0x00000002; 
const DWORD KEY_LEFT =		0x00000004;
#define		KEY_RIGHT		0x00000008; 

class CKeyManager
{
public:
	CKeyManager() {}; 
	~CKeyManager() {}; 
	
public:
	void Update_KeyManager()
	{
		m_dwKey = 0; 
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			m_dwKey |= KEY_LBUTTON; 
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
			m_dwKey |= KEY_RBUTTON;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			m_dwKey |= KEY_LEFT;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			m_dwKey |= KEY_RIGHT;
	}

	bool Key_UP(DWORD dwKey)
	{
		//0000 0011
		//0000 0001 &
		//=0000 0001

		//0000 0010 - RIGHTBUTTON 
		//0000 0001 & 
		//=0000 0000 
		if (m_dwKey & dwKey)
		{
			m_dwKeyUP |= dwKey; 
			return false; 
		}
		else if (m_dwKeyUP & dwKey)
		{
			m_dwKeyUP ^= dwKey; 
			return true;
		}

		return false; 
	}
	bool Key_DOWN(DWORD dwKey)
	{
		if ((m_dwKey & dwKey) && !(m_dwKeyDOWN & dwKey))
		{
			m_dwKeyDOWN |= dwKey;
			return true; 
		}
		else if (!(m_dwKey & dwKey) && (m_dwKeyDOWN & dwKey))
		{
			m_dwKeyDOWN ^= dwKey; 
			return false; 
		}
		return false; 
	}
	bool Key_Pressing(DWORD dwKey)
	{
		if (m_dwKey & dwKey)
		{
			return true; 
		}
		return false; 
	}
private:
	DWORD m_dwKey = 0; 
	DWORD m_dwKeyUP = 0; 
	DWORD m_dwKeyDOWN = 0;
};
int main()
{
	CKeyManager tKeyMgr; 
	while (true)
	{
		tKeyMgr.Update_KeyManager(); 
		if (tKeyMgr.Key_Pressing(KEY_LBUTTON))
		{
			cout << "김재덕은 잭스키스인가!? " << endl; 
		}
	}
    return 0;
}

