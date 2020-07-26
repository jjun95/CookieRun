#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	:m_fSpeed(0)
{
	ZeroMemory(&m_tInfo, sizeof(INFO)); 
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}


CObj::~CObj()
{
}

void CObj::Update_Rect_Object(int left, int top, int right, int bottom)
{
	m_tRect.left = LONG(left);
	m_tRect.top = LONG(top);
	m_tRect.right = LONG(right);
	m_tRect.bottom = LONG(bottom);
}

void CObj::MoveFrame() 
{
	if (m_tFrame.dwFrameTime + m_tFrame.dwFrameSpeed < GetTickCount()) {
		++m_tFrame.iStartFrame;
		m_tFrame.dwFrameTime = GetTickCount();
	}
	if (m_tFrame.iStartFrame > m_tFrame.iEndFrame)
		m_tFrame.iStartFrame = m_tFrame.iDefaultStartFrame;
}
