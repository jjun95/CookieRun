#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Ready_Object()
{
	m_tInfo.fX = 400.f; 
	m_tInfo.fY = 200.f; 
	m_tInfo.iCX = 100; 
	m_tInfo.iCY = 100; 
	m_fSpeed = 0.f; 
}

int CMonster::Update_Object()
{
// 	if (m_bIsDead)
// 		return OBJ_DEAD;
//m_tInfo.fX -= m_fSpeed; 
	if (nullptr == m_pTarget )
		return OBJ_DEAD; 

	// 목적지 빼기 출발지 
	float fX = m_pTarget->Get_Info()->fX - m_tInfo.fX; 
	float fY = m_pTarget->Get_Info()->fY - m_tInfo.fY; 

	float fDist = sqrtf(fX * fX + fY * fY); 

	m_fAngle = acosf(fX / fDist); 
	if (m_pTarget->Get_Info()->fY > m_tInfo.fY)
		m_fAngle *= -1.f; 

	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed; 
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed; 

	return OBJ_NOEVENT;
}

void CMonster::LateUpdate_Object()
{
	CObj::Update_Rect_Object();
// 	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
// 		m_fSpeed *= -1.f;

}

void CMonster::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CMonster::Release_Object()
{
}
