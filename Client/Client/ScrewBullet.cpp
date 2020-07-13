#include "stdafx.h"
#include "ScrewBullet.h"


CScrewBullet::CScrewBullet()
{
}


CScrewBullet::~CScrewBullet()
{
}

void CScrewBullet::Ready_Object()
{
	m_fRevDist = 30.f;
	m_fRevSpeed = 5.f; 
	m_fSpeed = 2.f; 
	m_tInfo.iCX = 20; 
	m_tInfo.iCY = 20; 
}

int CScrewBullet::Update_Object()
{
	if (m_bIsInit)
	{
		m_tCenter.x = m_tInfo.fX; 
		m_tCenter.y = m_tInfo.fY; 
		m_bIsInit = false; 
	}
	m_fRevAngle += m_fRevSpeed; 
	m_tInfo.fX = m_tCenter.x + (cosf(DEGREETORADIAN(m_fRevAngle)) * m_fRevDist);
	m_tInfo.fY = m_tCenter.y - (sinf(DEGREETORADIAN(m_fRevAngle)) * m_fRevDist); 

	m_tCenter.x += cosf(DEGREETORADIAN(m_fAngle)) * m_fSpeed; 
	m_tCenter.y -= sinf(DEGREETORADIAN(m_fAngle)) * m_fSpeed; 
	return OBJ_NOEVENT;
}

void CScrewBullet::LateUpdate_Object()
{
}

void CScrewBullet::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CScrewBullet::Release_Object()
{
}
