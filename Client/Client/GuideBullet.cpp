#include "stdafx.h"
#include "GuideBullet.h"
#include "Obj_Manager.h"

CGuideBullet::CGuideBullet()
{
}


CGuideBullet::~CGuideBullet()
{
	Release_Object(); 
}

void CGuideBullet::Ready_Object()
{
	m_tInfo.iCX = 20; 
	m_tInfo.iCY = 20;
	m_fSpeed = 5.f; 
	
}

int CGuideBullet::Update_Object()
{
	m_pTarget = CObj_Manager::Get_Instance()->Get_Target(this, OBJ::OBJ_MONSTER);

	if (nullptr == m_pTarget)
		return OBJ_DEAD;

	float fX = m_pTarget->Get_Info()->fX - m_tInfo.fX; 
	float fY = m_pTarget->Get_Info()->fY - m_tInfo.fY; 
	float fDist = sqrt(fX * fX + fY * fY); 

	m_fAngle = acosf(fX / fDist); 
	if (m_pTarget->Get_Info()->fY > m_tInfo.fY)
		m_fAngle *= -1.f; 

	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed; 
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed; 


	return OBJ_NOEVENT;
}

void CGuideBullet::LateUpdate_Object()
{



}

void CGuideBullet::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CGuideBullet::Release_Object()
{
}
