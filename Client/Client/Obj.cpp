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

void CObj::Update_Rect_Object()
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.iCY >> 1));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.iCY >> 1));
}

void CObj::MoveFrame() 
{
	if (m_tFrame.dwFrameTime + m_tFrame.dwFrameSpeed < GetTickCount()) {
		++m_tFrame.iStartFrame;
		m_tFrame.dwFrameTime = GetTickCount();
	}
	if (m_tFrame.iStartFrame >= m_tFrame.iEndFrame)
		m_tFrame.iStartFrame = m_tFrame.iDefaultStartFrame;
}
