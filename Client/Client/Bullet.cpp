#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Ready_Object()
{
	m_tInfo.iCX = 25; 
	m_tInfo.iCY = 25; 
	m_fSpeed = 5.f; 
}

int CBullet::Update_Object()
{
	if (m_bIsDead)
		return OBJ_DEAD;

	m_tInfo.fX += cosf(m_fAngle * 3.14f / 180.f) * m_fSpeed; 
	m_tInfo.fY -= sinf(m_fAngle * 3.14f / 180.f) * m_fSpeed;
// 	switch (m_eDir)
// 	{
// 	case BULLET::╩С:
// 		m_tInfo.fY -= m_fSpeed;
// 		break;
// 	case BULLET::го:
// 		m_tInfo.fY += m_fSpeed;
// 		break;
// 	case BULLET::аб:
// 		m_tInfo.fX -= m_fSpeed;
// 		break;
// 	case BULLET::©Л:
// 		m_tInfo.fX += m_fSpeed;
// 		break;
// 	default:
// 		m_tInfo.fY -= m_fSpeed;
// 		break;
// 	}
// 	
	return OBJ_NOEVENT;
}

void CBullet::LateUpdate_Object()
{
	CObj::Update_Rect_Object();
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right || 100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
		m_bIsDead = true; 

}

void CBullet::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object(); 
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
}

void CBullet::Release_Object()
{
}
