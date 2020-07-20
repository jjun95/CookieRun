#include "stdafx.h"
#include "MainApp.h"
#include "Player.h"
#include "Bullet.h"
#include "Mouse.h"
#include "Monster.h"
#include "Obj_Manager.h"
#include "Map_manager.h"
#include "Bitmap_Manager.h"
#include "Scroll_Manager.h"
#include "Scene_Manager.h"
#include "Maps.h"

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
	//m_dwOldTime = GetTickCount(); 
	m_hDC = GetDC(g_hWND); 

	//�׸� �����ϱ�
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/BackBuffer.bmp", L"BackBuffer");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/Back01.bmp", L"Back01");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/Back01-1.bmp", L"Back01-1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Ground1.bmp", L"Ground1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/ButterCream.bmp", L"ButterCream");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle01.bmp", L"Obstacle01");


	//CObj* pObj = ; 
	//m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_PLAYER);

	CObj* pObj = CAbstractFactory<CMouse>::Create(); 
	m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_MOUSE);

	CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_PLAY);
}

void CMainApp::Update_MainApp()
{
	CKey_Manager::Get_Instance()->Update_KeyManager(); 
	CScene_Manager::Get_Instance()->Update_SceneManager();
	//m_pObj_Manager->Update_ObjectManager(); 
}

void CMainApp::LateUpdate_MainApp()
{
	//m_pObj_Manager->LateUpdate_ObjectManager();
	CScene_Manager::Get_Instance()->LateUpdate_SceneManager();
}

void CMainApp::Render_MainApp()
{
	HDC hBack = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"BackBuffer");
	if (nullptr == hBack)
		return;
	HDC hMemDC = CBitmap_Manager::Get_Instance()->Find_Image_BitmapManager(L"Back01");
	BitBlt(hBack, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	//BitBlt(m_hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CScene_Manager::Get_Instance()->Render_SceneManager(hBack);
	//CScene_Manager::Get_Instance()->Render_SceneManager(m_hDC);

	//++m_iFPS; 
	//if (m_dwOldTime + 1000 < GetTickCount() )
	//{
	//	swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
	//	m_iFPS = 0; 
	//	m_dwOldTime = GetTickCount(); 
	//}
	TextOut(m_hDC, 600, 50, m_szFPS, lstrlen(m_szFPS));
	SetWindowText(g_hWND, m_szFPS);
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBack, 0, 0, SRCCOPY);
}

void CMainApp::Release_MainApp()
{
	ReleaseDC(g_hWND, m_hDC);
	m_pObj_Manager->Destroy_Instance();
	//CLine_Manager::Destroy_Instance(); 
	CMap_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 
	CBitmap_Manager::Destroy_Instance();
	CScene_Manager::Destroy_Instance();

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
