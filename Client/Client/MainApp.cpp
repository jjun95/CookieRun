#include "stdafx.h"
#include "MainApp.h"
#include "Player.h"
#include "Mouse.h"
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

	//그림 저장하기
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/BackBuffer.bmp", L"BackBuffer");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/Back01.bmp", L"Back01");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/BackGround/Back01-1.bmp", L"Back01-1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Ground1.bmp", L"Ground1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/ButterCream.bmp", L"ButterCream");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle1.bmp", L"Obstacle1");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle2.bmp", L"Obstacle2");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle3.bmp", L"Obstacle3");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Obstacle/Obstacle4.bmp", L"Obstacle4");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/SilverCoin.bmp", L"SilverCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/GoldCoin.bmp", L"GoldCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Coin/BigCoin.bmp", L"BigCoin");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/PinkBear.bmp", L"PinkBear");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/YellowBear.bmp", L"YellowBear");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/BaseJelly.bmp", L"BaseJelly");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/MiddleJelly.bmp", L"MiddleJelly");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Jelly/BigJelly.bmp", L"BigJelly");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Dumbbell.bmp", L"Dumbbell");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/HpBar.bmp", L"HpBar");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/HpBarBack.bmp", L"HpBarBack");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/HpBarAcc.bmp", L"HpBarAcc");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/SmallHp.bmp", L"SmallHp");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/BigHp.bmp", L"BigHp");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Booster.bmp", L"Booster");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Giant.bmp", L"Giant");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Item/Magnet.bmp", L"Magnet");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Load2.bmp", L"Load");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Upgrade.bmp", L"UpgradeBack");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Button/Upgrade.bmp", L"Upgrade");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Button/Start.bmp", L"Start");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Button/UpgradePan.bmp", L"UpgradePan");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Button/Selected.bmp", L"Selected");
	CBitmap_Manager::Get_Instance()->Insert_Texture_BitmapManager(L"../Image/Result.bmp", L"Result");


	//CObj* pObj = ; 
	//m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_PLAYER);

	CObj* pObj = CAbstractFactory<CMouse>::Create(); 
	m_pObj_Manager->Add_Object(pObj, OBJ::OBJ_MOUSE);

	pObj = CAbstractFactory<CPlayer>::Create();
	CObj_Manager::Get_Instance()->Add_Object(pObj, OBJ::OBJ_PLAYER);

	CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_LOAD, pObj);
	//CScene_Manager::Get_Instance()->Scene_Change_SceneManager(CScene_Manager::SCENE_PLAY);
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

	++m_iFPS; 
	if (m_dwOldTime + 1000 < GetTickCount() )
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		m_iFPS = 0; 
		m_dwOldTime = GetTickCount(); 
	}
	//TextOut(m_hDC, 600, 50, m_szFPS, lstrlen(m_szFPS));
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
디자인 패턴 - 프로그래밍할때 대게 이러한 상황이라면 이러한 형태의 클래스의 디자인을 사용하는
것이 대게 좋더라 라는 것이 모이고 모여서 이를 바탕으로 클래스간의 행동 양식을 분류하고 각각에
대해 객체지향적인 설계를 따른 노하우들이 차곡창곡 쌓이고 싸여 코드의 구조들을 일정한 형태로
만들어 재사용하기 편하게 만든 일정한 패턴이 디자인 패턴! 

이 용어를 사용하기 시작한건 GOF 라 불리는 4명의 컴터 공학자들이 만든책 
재이용 가능한 객체지향 소프트웨어 요소 - 디자인패턴 

// 추상팩토리 패턴 - 생성 패턴의 일종으로 객체를 만드는 절차를 추상화 시킨 패턴. 즉, 객체
생성시 동반되는 작업들을 추상화 시킨 패턴이다. 

// 이터레이터 패턴(반복자 패턴) - 내부 표현 방식을 공개하지 않고 순차적인 접근 방법을 제공하는 패턴이 이론이고 
우리는 이 패턴을 사용하는 목적은 공통된 부모를 갖는 오브젝트들을 하나의 컨테이너로 관리 하겠다 라는 것이 목적. 

상속과 다형성이 있기 때문에 가능한 패턴이고 객체 관리에 대한 디자인 패턴이다. 

// 메디에이터 패턴 (중재자 패턴) - 다 : 다 관계에서 다 : 1 관계로 복잡도를 떨어트리는 디자인패턴이다. 

// 싱글톤패턴 - 객체 생성을 제한하는 패턴. 최소단위가 1개이기 때문에 싱글톤이라 함. 


*/
