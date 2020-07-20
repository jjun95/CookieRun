#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}


CMouse::~CMouse()
{
}

void CMouse::Ready_Object()
{
	//m_tInfo.iCX = 100; 
	//m_tInfo.iCY = 100; 
	ShowCursor(true);
}

int CMouse::Update_Object()
{
	// 마우스 위치를 얻어오려면!? 
	POINT pt = {}; 
	GetCursorPos(&pt); 
	ScreenToClient(g_hWND, &pt); 
	m_tInfo.fX = float(pt.x); 
	m_tInfo.fY = float(pt.y); 
	return 0;
}

void CMouse::LateUpdate_Object()
{
}

void CMouse::Render_Object(HDC hDC)
{
	//CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CMouse::Release_Object()
{
}
