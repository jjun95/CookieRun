#include "stdafx.h"
#include "Maps.h"
#include "Obj.h"


CMaps::CMaps()
{
}

CMaps::CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID)
	: m_tInfo(mapInfo), m_eDTID(eDTID)
{
}

CMaps::CMaps(MAPINFO & mapInfo, MAP::DETAILED_ID eDTID, CObj * pPet)
	: m_tInfo(mapInfo), m_eDTID(eDTID) , m_pPet(pPet)
{
}


CMaps::~CMaps()
{
}

int CMaps::Update_Map()
{
	if (m_bIsDead)
		return OBJ_DEAD;
	if (m_dwTime + 10 <= GetTickCount()) {
		m_fSpeed -= m_fSpeedInc;
	}
	if (m_bIsMagnet) {
		int dx = m_tInfo.tPoint.fX + m_fSpeed - m_pPet->Get_Info()->fX;
		int dy = m_tInfo.tPoint.fY - m_pPet->Get_Info()->fY;
		int dist = sqrt(dx*dx + dy * dy);
		if (dx >= 0 && dist < 500) {
			m_tInfo.tPoint.fX -= 5 * dx / dist;
			m_tInfo.tPoint.fY -= 15 * dy / dist;
		}
		//if (dx > 0 && dist < 500) {
		//	m_tInfo.tPoint.fX -= 5 * dist / dx ;
		//	if (dy != 0)
		//		m_tInfo.tPoint.fY -= 5 * dist / dy;
		//}
	}
	Update_Rect_Object();
	MoveFrame();
	return OBJ_NOEVENT;
}

void CMaps::LateUpdate_Map()
{
	if (m_tRect.right + m_fSpeed <= 0)
		m_bIsDead = true;
}

void CMaps::Update_Rect_Object()
{
	m_tRect.left = LONG(m_tInfo.tPoint.fX - (m_tInfo.tPoint.iCX >> 1));
	m_tRect.top = LONG(m_tInfo.tPoint.fY - (m_tInfo.tPoint.iCY >> 1));
	m_tRect.right = LONG(m_tInfo.tPoint.fX + (m_tInfo.tPoint.iCX >> 1));
	m_tRect.bottom = LONG(m_tInfo.tPoint.fY + (m_tInfo.tPoint.iCY >> 1));
}

void CMaps::MoveFrame()
{
	if (m_tFrame.dwFrameTime + m_tFrame.dwFrameSpeed < GetTickCount()) {
		++m_tFrame.iStartFrame;
		m_tFrame.dwFrameTime = GetTickCount();
	}
	if (m_tFrame.iStartFrame >= m_tFrame.iEndFrame)
		m_tFrame.iStartFrame = m_tFrame.iDefaultStartFrame;
}
