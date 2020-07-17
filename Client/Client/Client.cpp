// Client.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Client.h"
#include "MainApp.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND g_hWND; 
// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
// HANDLE - �ĺ��ϱ� ���� ���� ��ȣ - unsigned ������ �����̴�. 
// �ڵ��� ��� ����ڰ� �ο��ϴ� ���� �ƴ϶� �ü���� ���� �ο��ϴ� �����̴�. 
// ������� ġ�� �ֹε�Ϲ�ȣ�� ���� ����. 
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

	CMainApp tMain; 
	tMain.Ready_MainApp();
    MSG msg;
	msg.message = WM_NULL; 
    // �⺻ �޽��� �����Դϴ�.
	// ������� ��ȭ�� �ü����� ���ϱ⵵�Ѵ�. 

	// ����ڰ� Ű�� ������ ->�ϵ����� �̺�Ʈ�� ����-> OS�� �̺�Ʈ�� �ν� -> �޽��� �߻���Ų�� -> �������α׷����� �ű⿡���� �޽����� ó���� �Ѵ�. 
	// �ü���� �����ϰ� �ִ� �޽��� ť��� ������ �޽����� ������ ������ �����Ѵ�. 
	// GetMessage�� ��� ���� ���̻� �о���� �޽����� ���ٸ� ���ŷ���¿� ��Ʈ����. 
	//GetTickCount() �뷫 õ���� ����. 
	DWORD dwOldTime = GetTickCount(); 
    while (WM_QUIT != msg.message)
    {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		if (dwOldTime + 10 < GetTickCount())
		{
		
			tMain.Update_MainApp();
			tMain.LateUpdate_MainApp();
			tMain.Render_MainApp();
			dwOldTime = GetTickCount();
		}
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL; /*MAKEINTRESOURCEW(IDC_CLIENT);*/
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   // ���ڿ����� SBCS�� MBCS, WBCS
   //SBCS - �̱� ����Ʈ �ɸ��� �� - ���ڸ� ó���Կ� �־� 1����Ʈ�� ó���� �ϰڴ�. 
   // ��ǥ���� �ڵ�ǥ�� �ƽ�Ű�ڵ�ǥ. char

   //MBCS - 1����Ʈ�� ó���Ҽ� �ִ� ���ڴ� 1����Ʈ�� ó���� �ϵ� ���� 1����Ʈ�� ó���Ҽ� ���� ���ڿ��̶�� 2����Ʈ �̻��� ����ϰڴ�. 
   // ��ǥ���� �ڵ�ǥ�� cp949��� �ڵ�ǥ. 

   // WBCS - ���ڸ� 2����Ʈ �̻����� ó���� �ϰڴ�. 
   // �����ڵ�ǥ�� �̰��� ���Ѵ�.  wchar 


   TCHAR szTitle[64] = __T("��������"); 
   RECT rc = { 0, 0, WINCX, WINCY }; 
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   g_hWND = hWnd; 
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
// CALLBACK - ����ڰ� ���� ȣ���ϴ� �Լ��� �ƴ� �ü���� ȣ���ϴ� �Լ��� �ٴ´�. 
// ���߿� MFC ���� �˴� �ݹ� �����̱� ������ �˾Ƶθ� ����. 

/*
�Լ� ȣ�� �Ծ� - cdecl, stdcall, fastcall, thiscall 
�Լ� ȣ�� �Ծ� - �Լ��� ������ ����Ǹ� �Ҵ�Ǿ��� ������ �����ؾ��ϴµ� �Լ��� ȣ���� ȣ������� ������ �� ���ΰ� �ƴϸ� ��ȣ���ڿ��� ������ �Ұ��ΰ��� ���� ��� , �� �Ծ��� ���Ѵ�. 

cdecl - C/C++�� ����Ʈ �Լ�ȣ��Ծ�. 
��ǥ������ �������� �Լ��� �� cdecl�� ���ϰ� �ȴ�. 
�Լ� ȣ���ڰ� ������ �����Ѵ�. 
��, �Լ��� ȣ���ѳ��� ȣ����ѳ��� ������ �������ش�. 
���ѳ��� �� ���� ��� ���ڰ� ������ �𸥴�. 
�׷��� �Լ��� ȣ���ѳ��� ������ ��������. 
ex) printf, scanf 

stdcall - Win32 API�� ����Ʈ �Լ� ȣ�� �Ծ� 
��ǥ������ �������� �Լ��� �� stdcall ���Ѵ�. 
�ִ� ��ȣ���ڰ� ������ �����Ѵ�. 

fastcall - ���״�� ���� �Լ�ȣ��Ծ�. 

thiscall - this �����͸� ����ϴ� �Լ����� ����ϴ� �Լ� ȣ��Ծ� ex ����Լ�. ���� ... 

*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//wParam - �ΰ����� �޽��� ������ ��� �ִ� ����. Ű���� ���� ������ ��� �ִ�. 
	//lParam - �ΰ����� �޽��� ������ ��� �ִ� ����. ���콺 ���� ������ ��� �ִ�. 
    switch (message)
    {

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break; 
		default:
			break;
		}
		break;
	}
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

