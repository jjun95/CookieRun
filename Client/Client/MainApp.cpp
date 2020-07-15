#include "stdafx.h"
#include "MainApp.h"
#include "Player.h"
#include "Bullet.h"
#include "Mouse.h"
#include "Monster.h"
#include "Obj_Manager.h"
#include "Line_Manager.h"
#include "Map_manager.h"
CMainApp::CMainApp()
	:m_pObj_Manager(CObj_Manager::Get_Instance())
{

}


CMainApp::~CMainApp()
{
	Release_MainApp(); 
}

void CMainApp::Ready_MainApp()
{
	m_dwOldTime = GetTickCount(); 
	m_hDC = GetDC(g_hWND); 
	CObj* pObj = CAbstractFactory<CPlayer>::Create(); 
	m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_PLAYER);

	pObj = CAbstractFactory<CMouse>::Create(); 
	m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_MOUSE);

	CLine_Manager::Get_Instance()->Ready_LineManager(); 
	CMap_Manager::Get_Instance()->Ready_MapManager(); 
}

void CMainApp::Update_MainApp()
{
	CKey_Manager::Get_Instance()->Update_KeyManager(); 

	m_pObj_Manager->Update_ObjectManager(); 
}

void CMainApp::LateUpdate_MainApp()
{
	m_pObj_Manager->LateUpdate_ObjectManager();
}

void CMainApp::Render_MainApp()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY); 
	m_pObj_Manager->Render_ObjectManager(m_hDC); 
	CLine_Manager::Get_Instance()->Render_LineManager(m_hDC); 
	CMap_Manager::Get_Instance()->Render_MapManager(m_hDC); 

	++m_iFPS; 
	if (m_dwOldTime + 1000 < GetTickCount() )
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		m_iFPS = 0; 
		m_dwOldTime = GetTickCount(); 
	}
	TextOut(m_hDC, 600, 50, m_szFPS, lstrlen(m_szFPS));
	SetWindowText(g_hWND, m_szFPS);
}

void CMainApp::Release_MainApp()
{
	ReleaseDC(g_hWND, m_hDC);
	m_pObj_Manager->Destroy_Instance();
	CLine_Manager::Destroy_Instance(); 
	CMap_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 

}

/*
������ ���� - ���α׷����Ҷ� ��� �̷��� ��Ȳ�̶�� �̷��� ������ Ŭ������ �������� ����ϴ�
���� ��� ������ ��� ���� ���̰� �𿩼� �̸� �������� Ŭ�������� �ൿ ����� �з��ϰ� ������
���� ��ü�������� ���踦 ���� ���Ͽ���� ����â�� ���̰� �ο� �ڵ��� �������� ������ ���·�
����� �����ϱ� ���ϰ� ���� ������ ������ ������ ����! 

�� �� ����ϱ� �����Ѱ� GOF �� �Ҹ��� 4���� ���� �����ڵ��� ����å 
���̿� ������ ��ü���� ����Ʈ���� ��� - ���������� 

// �߻����丮 ���� - ���� ������ �������� ��ü�� ����� ������ �߻�ȭ ��Ų ����. ��, ��ü
������ ���ݵǴ� �۾����� �߻�ȭ ��Ų �����̴�. 

// ���ͷ����� ����(�ݺ��� ����) - ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ������ �̷��̰� 
�츮�� �� ������ ����ϴ� ������ ����� �θ� ���� ������Ʈ���� �ϳ��� �����̳ʷ� ���� �ϰڴ� ��� ���� ����. 

��Ӱ� �������� �ֱ� ������ ������ �����̰� ��ü ������ ���� ������ �����̴�. 

// �޵����� ���� (������ ����) - �� : �� ���迡�� �� : 1 ����� ���⵵�� ����Ʈ���� �����������̴�. 

// �̱������� - ��ü ������ �����ϴ� ����. �ּҴ����� 1���̱� ������ �̱����̶� ��. 


*/