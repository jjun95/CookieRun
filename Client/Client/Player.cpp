#include "stdafx.h"
#include "Player.h"
#include "Obj_Manager.h"
#include "Bitmap_Manager.h"
#include "Map_Manager.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_Object(); 
}

void CPlayer::KeyCheck()
{
	if (CKey_Manager::Get_Instance()->Key_Pressing(KEY_DOWN)) {
		m_eNextState = OBJ::PLAYER_SLIDE;
	}
	if (CKey_Manager::Get_Instance()->Key_UP(KEY_DOWN)) {
		m_eNextState = OBJ::PLAYER_RUN;
	}
}

bool CPlayer::IsJumping()
{
	//if (!m_bIsHit) {
		if (m_dwJumpTime + 150 < GetTickCount()) {
			if (m_bIsJump && (m_bIsDoubleJump == false)) {
				if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_UP)) {
					m_fStartHeight = m_tInfo.fY;
					m_bIsDoubleJump = true;
					m_fTime = 0.f;
					m_eNextState = OBJ::PLAYER_DOUBLEJUMP;
				}
			}
		}
		if (!m_bIsJump)
		{
			if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_UP))
			{
				m_fStartHeight = m_tInfo.fY;
				m_bIsJump = true;
				m_dwJumpTime = GetTickCount();
				m_eNextState = OBJ::PLAYER_JUMP;
			}
		}
	//}
	m_fTime += 0.2f;

	if (m_bIsDoubleJump) {
		m_fHeight = 2*(m_fTime * m_fTime * -GRAVITY / 2) + (m_fTime * m_fSpeed);
		m_tInfo.fY = -m_fHeight + m_fStartHeight;
	}
	else if (m_bIsJump)//첫번째 점프할 때
	{
		m_fHeight = 2*(m_fTime * m_fTime * -GRAVITY / 2) + (m_fTime * m_fSpeed);
		m_tInfo.fY = -m_fHeight + m_fStartHeight;

	}
	else {
		m_tInfo.fY += m_fTime * GRAVITY;
	}

	if (m_bIsJump)
		return true;
	else return false;
}

void CPlayer::Animation_Change()
{
	if (m_eCurState != m_eNextState) {
		switch (m_eNextState) {
		case OBJ::PLAYER_RUN:
			m_tFrame.iDefaultStartFrame = 0;
			m_tFrame.iStartFrame = 0;
			m_tFrame.iEndFrame = 3;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJ::PLAYER_SLIDE:
			m_tFrame.iDefaultStartFrame = 9;
			m_tFrame.iStartFrame = 9;
			m_tFrame.iEndFrame = 10;
			m_tFrame.dwFrameSpeed = 1000;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJ::PLAYER_RUSH:
			m_tFrame.iDefaultStartFrame = 4;
			m_tFrame.iStartFrame = 4;
			m_tFrame.iEndFrame = 7;
			m_tFrame.dwFrameSpeed = 70;
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJ::PLAYER_JUMP:
			m_tFrame.iDefaultStartFrame = 8;
			m_tFrame.iStartFrame = 8;
			m_tFrame.iEndFrame = 8;
			m_tFrame.dwFrameSpeed = 1000;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJ::PLAYER_DOUBLEJUMP:
			m_tFrame.iDefaultStartFrame = 8;
			m_tFrame.iStartFrame = 1;
			m_tFrame.iEndFrame = 8;
			m_tFrame.dwFrameSpeed = 200;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJ::PLAYER_PAIN:
			m_tFrame.iDefaultStartFrame = 3;
			m_tFrame.iStartFrame = 3;
			m_tFrame.iEndFrame = 4;
			m_tFrame.dwFrameSpeed = 500;
			m_tFrame.iSceneFrame = 5;
			break;
		case OBJ::PLAYER_DIE:
			m_tFrame.iDefaultStartFrame = 5;
			m_tFrame.iStartFrame = 5;
			m_tFrame.iEndFrame = 9;
			m_tFrame.dwFrameSpeed = 500;
			m_tFrame.iSceneFrame = 4;
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}

void CPlayer::Stop_Jump()
{
	m_fTime = 0.f;
	if (m_bIsJump) {
		m_bIsJump = false;
		m_bIsDoubleJump = false;
		m_dwJumpTime = GetTickCount();
		m_eNextState = OBJ::PLAYER_RUN;
	}
}

void CPlayer::Ready_Object()
{
	m_tInfo.fX = 300.f; 
	m_tInfo.fY = WINCY - 280.f; 
	m_tInfo.iCX = PLAYERSIZE; 
	m_tInfo.iCY = PLAYERSIZE;
	m_fSpeed = 80.f; 
	m_dwJumpTime = GetTickCount();
	m_iMaxHp = 150;
	m_iHp = m_iMaxHp;
	m_szFrameKey = L"ButterCream";
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.iSceneFrame = 1;
	m_tFrame.dwFrameTime = GetTickCount();
	m_eCurState = OBJ::PLAYER_RUN;
	m_eNextState = OBJ::PLAYER_RUN;
	//CObj::Update_Rect_Object(m_tInfo.fX - (m_tInfo.iCX >> 4), m_tInfo.fY, m_tInfo.fX + (m_tInfo.iCX >> 3), m_tInfo.fY + (m_tInfo.iCY >> 1));
}

int CPlayer::Update_Object()
{
	if (!IsJumping())
		KeyCheck(); 
	Animation_Change();
	CObj::MoveFrame();
	return 0;
}

void CPlayer::LateUpdate_Object()
{
	if (m_bIsHit) {
		if (m_dwHitTime + 100 < GetTickCount())
			CMap_Manager::Get_Instance()->Set_Speed(5);
		if ((m_eCurState == OBJ::PLAYER_PAIN) && m_dwHitTime + 300 < GetTickCount()) {
			m_eNextState = OBJ::PLAYER_RUN;
		}
		if (m_dwHitTime + 1000 < GetTickCount()) {
			m_bIsHit = false;
		}
	}
}

void CPlayer::Render_Object(HDC hDC)
{
	if(m_eCurState == OBJ::PLAYER_SLIDE)
		CObj::Update_Rect_Object(m_tInfo.fX - (m_tInfo.iCX >> 3), m_tInfo.fY + (m_tInfo.iCX / 3.f), m_tInfo.fX + (m_tInfo.iCX >> 2), m_tInfo.fY + (m_tInfo.iCY >> 1));
	else
		CObj::Update_Rect_Object(m_tInfo.fX - (m_tInfo.iCX >> 6), m_tInfo.fY, m_tInfo.fX + (m_tInfo.iCX >> 3), m_tInfo.fY + (m_tInfo.iCY / 2.2f));
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(m_szFrameKey);
	if (nullptr == hMemDC)
		return;

	if (!blink){
		GdiTransparentBlt(hDC, m_tInfo.fX - (PLAYERSIZE >> 1),
			m_tInfo.fY - (PLAYERSIZE >> 1),
			m_tInfo.iCX,
			m_tInfo.iCY,
			hMemDC,
			m_tInfo.iCX * m_tFrame.iStartFrame, m_tInfo.iCY * m_tFrame.iSceneFrame,
			m_tInfo.iCX,
			m_tInfo.iCY,
			RGB(255, 0, 255));
		if(m_bIsHit)
			blink = true;
	}
	else{
		blink = false;
	}
	//충돌 처리할 rect 확인
	MoveToEx(hDC, m_tRect.left, m_tRect.top, nullptr);
	LineTo(hDC, m_tRect.right, m_tRect.top);
	LineTo(hDC, m_tRect.right, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.bottom);
	LineTo(hDC, m_tRect.left, m_tRect.top);
	// 각도에서 라디안으로 치환하기 위해서는// 각도 * PI / 180 = 라디안
	// 라디안에서 각도로 치환하기 위해서는// 라디안 * 180 / PI = 각도 
}

void CPlayer::Release_Object()
{
}