#include "stdafx.h"
#include "Line_Manager.h"
#include "Line.h"

CLine_Manager* CLine_Manager::m_pInstance = nullptr; 
CLine_Manager::CLine_Manager()
{
}


CLine_Manager::~CLine_Manager()
{
	Release_LineManager(); 
}

void CLine_Manager::SaveData()
{

	HANDLE hFile = CreateFile(__T("../Data/Line.dat"),GENERIC_WRITE, 0, NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, nullptr); 

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("SaveData Failed"), __T("LineManager"), MB_OK);
		return;
	}
	DWORD dwByte = 0; 
	for (auto& pLine : m_listLine)
	{
		WriteFile(hFile, pLine->Get_LineInfo(), sizeof(LINEINFO), &dwByte, nullptr);
	}
	MessageBox(nullptr, L"LineSave 성공!", L"라인매니저!", MB_OK);
	CloseHandle(hFile);
}

void CLine_Manager::Ready_LineManager()
{
}

void CLine_Manager::Update_LineManager()
{
	// 여기에서 사용자가 딱 마우스를 찍었을 때 ! 
	//선을 생성하고 선의 시작점을 잡아주자! 
	POINT pt = {};
	GetCursorPos(&pt); 
	ScreenToClient(g_hWND, &pt); 

	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_LBUTTON))
	{
		CLine* pLine = new CLine(LINEINFO(LINEPOS(float(pt.x), float(pt.y)), LINEPOS(float(pt.x), float(pt.y)))); 
		m_listLine.emplace_back(pLine);
	}
	if (CKey_Manager::Get_Instance()->Key_UP(KEY_LBUTTON))
	{
		m_listLine.back()->Set_RightPos(LINEPOS(float(pt.x), float(pt.y)));
	}
	if (CKey_Manager::Get_Instance()->Key_DOWN(KEY_S))
	{
		SaveData();
	}

}

void CLine_Manager::Render_LineManager(HDC hDC)
{
	for (auto& pLine : m_listLine)
	{
		pLine->Render_Line(hDC); 
	}
}

void CLine_Manager::Release_LineManager()
{
	for_each(m_listLine.begin(), m_listLine.end(), Safe_Delete<CLine*>); 
}
