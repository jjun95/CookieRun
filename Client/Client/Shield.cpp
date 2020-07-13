#include "stdafx.h"
#include "Shield.h"


CShield::CShield()
{
}


CShield::~CShield()
{
	Release_Object(); 
}

void CShield::Ready_Object()
{
	m_tInfo.iCX = 20; 
	m_tInfo.iCY = 20; 
	m_fSpeed = 5.f; 
	m_fDist = 50.f; 

}

int CShield::Update_Object()
{
	if (nullptr == m_pTarget)
		return OBJ_DEAD; 

	m_fAngle += m_fSpeed; 

	m_tInfo.fX = m_pTarget->Get_Info()->fX + (cosf(DEGREETORADIAN(m_fAngle)) * m_fDist);
	m_tInfo.fY = m_pTarget->Get_Info()->fY - (sinf(DEGREETORADIAN(m_fAngle)) * m_fDist);
	return OBJ_NOEVENT;
}

void CShield::LateUpdate_Object()
{
}

void CShield::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CShield::Release_Object()
{
}
