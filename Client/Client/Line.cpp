#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}

CLine::CLine(const LINEINFO & rLineInfo)
	: m_tInfo(rLineInfo)
{
}


CLine::~CLine()
{
}

void CLine::Render_Line(HDC hDC)
{
	MoveToEx(hDC, int(m_tInfo.tLPoint.fX), int(m_tInfo.tLPoint.fY), nullptr); 
	LineTo(hDC, (int)m_tInfo.tRPoint.fX, (int)m_tInfo.tRPoint.fY); 
}
