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

void CLine_Manager::LoadData()
{

	HANDLE hFile = CreateFile(__T("../Data/Line.dat"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(nullptr, __T("LoadData Failed"), __T("LineManager_Client"), MB_OK);
		return;
	}
	CLine* pLine = nullptr; 
	DWORD dwByte = 0;
	LINEINFO tLineInfo = {}; 
	while(true)
	{
		ReadFile(hFile, &tLineInfo, sizeof(LINEINFO), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		pLine = new CLine(tLineInfo);
		m_listLine.emplace_back(pLine); 
	}
	MessageBox(nullptr, L"LineLoad 성공!", L"라인매니저!", MB_OK);
	CloseHandle(hFile);
}

bool CLine_Manager::LineCollision_LineManager(float fInX, float * pOutY)
{
	if(m_listLine.empty())
		return false;

	CLine* pTarget = nullptr; 

	for (auto& pLine : m_listLine)
	{
		if (fInX >= pLine->Get_LineInfo()->tLPoint.fX && fInX <= pLine->Get_LineInfo()->tRPoint.fX)
			pTarget = pLine;
	}
	if (nullptr == pTarget)
		return false; 

	float x1 = pTarget->Get_LineInfo()->tLPoint.fX; 
	float y1 = pTarget->Get_LineInfo()->tLPoint.fY; 
	float x2 = pTarget->Get_LineInfo()->tRPoint.fX; 
	float y2 = pTarget->Get_LineInfo()->tRPoint.fY; 
	*pOutY = ((y2 - y1) / (x2 - x1)) * (fInX - x1) + y1;

	return true; 
}

void CLine_Manager::Ready_LineManager()
{
	LoadData();
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
