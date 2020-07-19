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
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_DOWN)) {
		m_tInfo.fY = WINCY - 180;
		m_tInfo.iCX = 160;
		m_tInfo.iCY = 120;
		m_eNextState = OBJ::PLAYER_SLIDE;
	}
	if (CKey_Manager::Get_Instance()->Key_UP(KEY_DOWN)) {
		m_tInfo.fY = WINCY - 200.f;
		m_tInfo.iCX = 70;
		m_tInfo.iCY = 160;
		m_eNextState = OBJ::PLAYER_RUN;
	}
}

void CPlayer::IsJumping()
{
	if (m_dwJumpTime + 200 < GetTickCount()) {
		if (m_bIsJump && !m_bIsDoubleJump) {
			if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_UP)) {
				m_bIsDoubleJump = true;
				m_fJumpAccel = 0.f;
				m_eNextState = OBJ::_PLAYER_DOUBLEJUMP;
			}
		}
	}
	if (!m_bIsJump){
		if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_UP))
		{
			m_bIsJump = true;
			m_dwJumpTime = GetTickCount();
			m_fStartfY = m_tInfo.fY;
			m_eNextState = OBJ::PLAYER_JUMP;
		}
	}

	bool IsColl = CMap_Manager::Get_Instance()->GroundCollision_MapManager(m_tInfo.fX, &m_fStartfY, m_tInfo.iCY);

	m_fJumpAccel += 0.1f;
	if (m_bIsJump || m_bIsDoubleJump) {
		m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;

		if (m_tInfo.fY > m_fStartfY) {
			m_tInfo.fY = m_fStartfY;
			m_bIsJump = false;
			m_bIsDoubleJump = false;
			m_eNextState = OBJ::PLAYER_RUN;
		}
		return;
	}
	else if (IsColl) {
		m_tInfo.fY = m_fStartfY;
		m_fJumpAccel = 0.f;
		m_bIsJump = false;
		m_bIsDoubleJump = false;
		m_eNextState = OBJ::PLAYER_RUN;
		return;
	}
	else {
		m_tInfo.fY += m_fJumpAccel * GRAVITY;
	}
	//float fY = m_tInfo.fY; 
	//bool IsColl = CMap_Manager::Get_Instance()->GroundCollision_MapManager(&fY, m_tInfo.iCY);
	//if (m_bIsJump)
	//{
	//	//자유낙하 공식// y = 힘 * sin@ * 시간 - 1/2 * 중력 * 시간 * 시간 
	//	m_tInfo.fY -= m_fJumpPower * m_fJumpAccel - GRAVITY * m_fJumpAccel * m_fJumpAccel * 0.5f;
	//	m_fJumpAccel += 0.1f;

	//	if (m_tInfo.fY > fY)
	//	{
	//		m_bIsJump = false;
	//		m_fJumpAccel = 0.f;
	//		m_tInfo.fY = fY;
	//	}
	//}
	//else if (IsColl)
	//	m_tInfo.fY = fY; 
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
		case OBJ::_PLAYER_DOUBLEJUMP:
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
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.iSceneFrame = 5;
			break;
		case OBJ::PLAYER_DIE:
			m_tFrame.iDefaultStartFrame = 5;
			m_tFrame.iStartFrame = 5;
			m_tFrame.iEndFrame = 9;
			m_tFrame.dwFrameSpeed = 500;
			m_tFrame.iSceneFrame = 4;
			break;
		}
	}
}

void CPlayer::Ready_Object()
{
	m_tInfo.fX = 300.f; 
	m_tInfo.fY = WINCY - 200.f; 
	m_tInfo.iCX = 70; 
	m_tInfo.iCY = 160; 
	m_fSpeed = 5.f; 
	m_dwJumpTime = GetTickCount();
	m_fJumpPower = 15.f;
	m_fStartfY = m_tInfo.fY;
	m_szFrameKey = L"ButterCream";
	m_tFrame.iDefaultStartFrame = 0;
	m_tFrame.iStartFrame = 0;
	m_tFrame.iEndFrame = 3;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.iSceneFrame = 1;
	m_tFrame.dwFrameTime = GetTickCount();
	m_eCurState = OBJ::PLAYER_RUN;
	m_eNextState = OBJ::PLAYER_RUN;
}

int CPlayer::Update_Object()
{
	KeyCheck(); 
	IsJumping(); 
	Animation_Change();
	CObj::MoveFrame();
	return 0;
}

void CPlayer::LateUpdate_Object()
{

}

void CPlayer::Render_Object(HDC hDC)
{
	CObj::Update_Rect_Object();

	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(m_szFrameKey);
	if (nullptr == hMemDC)
		return;
	//GdiTransparentBlt(hDC, m_tInfo.fX - (PLAYERSIZE >> 1),
	//	WINCY - (120 + PLAYERSIZE),
	//	PLAYERSIZE,
	//	PLAYERSIZE,
	//	hMemDC,
	//	PLAYERSIZE * m_tFrame.iStartFrame, PLAYERSIZE * m_tFrame.iSceneFrame,
	//	PLAYERSIZE,
	//	PLAYERSIZE,
	//	RGB(255, 0, 255));

	GdiTransparentBlt(hDC, m_tInfo.fX - (PLAYERSIZE >> 1),
		m_tInfo.fY - (m_tInfo.iCY * 1.5),
		PLAYERSIZE,
		PLAYERSIZE,
		hMemDC,
		PLAYERSIZE * m_tFrame.iStartFrame, PLAYERSIZE * m_tFrame.iSceneFrame,
		PLAYERSIZE,
		PLAYERSIZE,
		RGB(255, 0, 255));
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