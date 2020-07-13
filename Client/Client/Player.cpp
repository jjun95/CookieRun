#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "ScrewBullet.h"
#include "Obj_Manager.h"
#include "GuideBullet.h"
#include "Line_Manager.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_Object(); 
}

void CPlayer::KeyCheck()
{
	if (CKey_Manager::Get_Instance()->Key_Pressing(KEY_LEFT))
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_tInfo.fX += cosf(m_fAngle * 3.14f / 180.f) * m_fSpeed;
		m_tInfo.fY -= sinf(m_fAngle * 3.14f / 180.f) * m_fSpeed;

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_tInfo.fX += cosf(m_fAngle * 3.14f / 180.f) * -m_fSpeed;
		m_tInfo.fY -= sinf(m_fAngle * 3.14f / 180.f) * -m_fSpeed;

	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_bIsJump = true; 
// 	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
// 		CObj_Manager::Get_Instance()->Add_Object(CreateBullet<CBullet>(), OBJ::OBJ_BULLET);
// 	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
// 		CObj_Manager::Get_Instance()->Add_Object(CreateBullet<CScrewBullet>(), OBJ::OBJ_BULLET);
// 	if (GetAsyncKeyState('A') & 0x8000)
// 		CObj_Manager::Get_Instance()->Add_Object(CreateBullet<CGuideBullet>(), OBJ::OBJ_BULLET);
// 	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
// 		CObj_Manager::Get_Instance()->Add_Object(CreateShield(), OBJ::OBJ_SHIELD);
	// ���� Ű�� �����ִ����� �Ǻ����ִ� �Լ�. 
	// ���Լ��� 4������ ��ȯ���� ��ȯ�Ѵ�. 
	//0x0000
	//0x0001
	//0x8000
	//0x8001
	// 	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	// 	{
	// 		if (GetAsyncKeyState(VK_UP))
	// 		{
	// 			m_tInfo.fX += m_fSpeed / sqrtf(2);
	// 			m_tInfo.fY -= m_fSpeed / sqrtf(2); 
	// 		}
	// 		else if (GetAsyncKeyState(VK_DOWN))
	// 		{
	// 			m_tInfo.fX += m_fSpeed / sqrtf(2);
	// 			m_tInfo.fY += m_fSpeed / sqrtf(2);
	// 		}
	// 		else
	// 			m_tInfo.fX += m_fSpeed;
	// 	}
	// 		
	// 	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	// 	{
	// 		if (GetAsyncKeyState(VK_UP))
	// 		{
	// 			m_tInfo.fX -= m_fSpeed / sqrtf(2);
	// 			m_tInfo.fY -= m_fSpeed / sqrtf(2);
	// 		}
	// 		else if (GetAsyncKeyState(VK_DOWN))
	// 		{
	// 			m_tInfo.fX -= m_fSpeed / sqrtf(2);
	// 			m_tInfo.fY += m_fSpeed / sqrtf(2);
	// 		}
	// 		else
	// 		m_tInfo.fX -= m_fSpeed;
	// 	}
	// 	else if (GetAsyncKeyState(VK_UP) & 0x8000)
	// 		m_tInfo.fY -= m_fSpeed;
	// 	 if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	// 		m_tInfo.fY += m_fSpeed;
	// 
	// 	// ����� �̻��� �߻縦 ��� �ϸ� ������ ? 
	// 	if (GetAsyncKeyState('W') & 0x8000)
	// 		m_plistBullet->emplace_back(CreateBullet(BULLET::��)); 
	// 	if (GetAsyncKeyState('S') & 0x8000)
	// 		m_plistBullet->emplace_back(CreateBullet(BULLET::��));
	// 	if (GetAsyncKeyState('A') & 0x8000)
	// 		m_plistBullet->emplace_back(CreateBullet(BULLET::��));
	// 	if (GetAsyncKeyState('D') & 0x8000)
	// 		m_plistBullet->emplace_back(CreateBullet(BULLET::��));
}

void CPlayer::IsJumping()
{
	float fY = m_tInfo.fY; 
	bool IsColl =  CLine_Manager::Get_Instance()->LineCollision_LineManager(m_tInfo.fX, &fY);
	if (m_bIsJump)
	{
		//�������� ����// y = �� * sin@ * �ð� - 1/2 * �߷� * �ð� * �ð� 
		m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;
		m_fJumpAccel += 0.1f;

		if (m_tInfo.fY > fY)
		{
			m_bIsJump = false;
			m_fJumpAccel = 0.f;
			m_tInfo.fY = fY;
		}
	}
	else if (IsColl)
		m_tInfo.fY = fY; 
}

void CPlayer::Ready_Object()
{
	m_tInfo.fX = 400.f; 
	m_tInfo.fY = 300.f; 
	m_tInfo.iCX = 50; 
	m_tInfo.iCY = 50; 
	m_fSpeed = 5.f; 
	m_fDist = 50.f; 
	m_tPosin = {}; 
	m_fAngle = 0.f; 
	m_fJumpPower = 15.f; 

}

int CPlayer::Update_Object()
{
	KeyCheck(); 
	IsJumping(); 
	return 0;
}

void CPlayer::LateUpdate_Object()
{
	
}

void CPlayer::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object();

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	// �������� �������� ġȯ�ϱ� ���ؼ���// ���� * PI / 180 = ����
	// ���ȿ��� ������ ġȯ�ϱ� ���ؼ���// ���� * 180 / PI = ���� 
	m_tPosin.x = LONG(m_tInfo.fX + (cosf(m_fAngle * 3.141592f / 180.f) * m_fDist)); 
	m_tPosin.y = LONG(m_tInfo.fY - (sinf(m_fAngle * 3.14f / 180.f)* m_fDist));
	MoveToEx(hDC, int(m_tInfo.fX), int(m_tInfo.fY), nullptr); 
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release_Object()
{
}
// 
// CObj * CPlayer::CreateBullet()
// {
// 	CObj* pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY); 
// 	return pBullet;
// }
// 
// CObj * CPlayer::CreateBullet(BULLET::ID eDir)
// {
// 	CObj* pBullet = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY);
// 	dynamic_cast<CBullet*>(pBullet)->Set_Dir(eDir); 
// 	return pBullet;
// }
// 
// CObj * CPlayer::CreateBullet(float fAngle)
// {
// 	CObj* pBullet = CAbstractFactory<CBullet>::Create(float(m_tPosin.x), static_cast<float>(m_tPosin.y), fAngle);
// 	return pBullet;
// }

// CObj * CPlayer::CreateScrewBullet()
// {
// 	CObj* pInstance = CAbstractFactory<CScrewBullet>::Create(m_tInfo.fX, m_tInfo.fY, m_fAngle);
// 	return pInstance;
// }

CObj * CPlayer::CreateShield()
{
	CObj* pInstance = CAbstractFactory<CShield>::Create(m_tInfo.fX, m_tInfo.fY); 
	dynamic_cast<CShield*>(pInstance)->Set_Target(this);
	return pInstance;
}

