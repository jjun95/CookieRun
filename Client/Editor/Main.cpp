#include "stdafx.h"
#include "Main.h"
#include "Line_Manager.h"
#include "Key_Manager.h"

CMain::CMain()
{
}


CMain::~CMain()
{
	Release_Main(); 
}

void CMain::Ready_Main()
{
	m_hDC = GetDC(g_hWND); 
}

void CMain::Update_Main()
{
	CKey_Manager::Get_Instance()->Update_KeyManager();
	CLine_Manager::Get_Instance()->Update_LineManager();
}

void CMain::Render_Main()
{
	CLine_Manager::Get_Instance()->Render_LineManager(m_hDC); 

}

void CMain::Release_Main()
{
	CLine_Manager::Destroy_Instance(); 
	CKey_Manager::Destroy_Instance(); 
}
