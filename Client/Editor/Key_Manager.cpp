#include "stdafx.h"
#include "Key_Manager.h"
CKey_Manager* CKey_Manager::m_pInstance = nullptr; 

CKey_Manager::CKey_Manager()
{
}


CKey_Manager::~CKey_Manager()
{
}

void CKey_Manager::Update_KeyManager()
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
	if (GetAsyncKeyState('S') & 0x8000)
		m_dwKey |= KEY_S;
}

bool CKey_Manager::Key_UP(DWORD dwKey)
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

bool CKey_Manager::Key_DOWN(DWORD dwKey)
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

bool CKey_Manager::Key_Pressing(DWORD dwKey)
{
	if (m_dwKey & dwKey)
	{
		return true;
	}
	return false;
}
