// Client.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Client.h"
#include "MainApp.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND g_hWND; 
// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
// HANDLE - 식별하기 위한 고유 번호 - unsigned 형식의 정수이다. 
// 핸들의 경우 사용자가 부여하는 것이 아니라 운영체제가 직접 부여하는 정수이다. 
// 사람으로 치면 주민등록번호와 같은 역할. 
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

	CMainApp tMain; 
	tMain.Ready_MainApp();
    MSG msg;
	msg.message = WM_NULL; 
    // 기본 메시지 루프입니다.
	// 윈도우는 대화식 운영체제라고 말하기도한다. 

	// 사용자가 키를 누른다 ->하드웨어에서 이벤트를 감지-> OS가 이벤트를 인식 -> 메시지 발생시킨다 -> 응용프로그램에서 거기에따른 메시지를 처리를 한다. 
	// 운영체제가 유지하고 있는 메시지 큐라는 곳에서 메시지를 얻어오는 역할을 수행한다. 
	// GetMessage의 경우 만약 더이상 읽어들일 메시지가 없다면 블로킹상태에 빠트린다. 
	//GetTickCount() 대략 천분의 일초. 
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 문자열에는 SBCS와 MBCS, WBCS
   //SBCS - 싱글 바이트 케릭터 셋 - 문자를 처리함에 있어 1바이트로 처리를 하겠다. 
   // 대표적인 코드표가 아스키코드표. char

   //MBCS - 1바이트로 처리할수 있는 문자는 1바이트로 처리를 하되 만약 1바이트로 처리할수 없는 문자열이라면 2바이트 이상을 사용하겠다. 
   // 대표적인 코드표가 cp949라는 코드표. 

   // WBCS - 문자를 2바이트 이상으로 처리를 하겠다. 
   // 유니코드표가 이곳에 속한다.  wchar 


   TCHAR szTitle[64] = __T("공부하자"); 
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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
// CALLBACK - 사용자가 직접 호출하는 함수가 아닌 운영체제가 호출하는 함수에 붙는다. 
// 나중에 MFC 들어가면 죄다 콜백 형식이기 때문에 알아두면 좋다. 

/*
함수 호출 규약 - cdecl, stdcall, fastcall, thiscall 
함수 호출 규약 - 함수의 실행이 종료되면 할당되었떤 스텍을 해제해야하는데 함수를 호출한 호출원에서 정리를 할 것인가 아니면 피호출자에서 정리를 할것인가에 대한 약속 , 즉 규약을 뜻한다. 

cdecl - C/C++의 디폴트 함수호출규약. 
대표적으로 가변인자 함수가 이 cdecl에 속하게 된다. 
함수 호출자가 스택을 정리한다. 
즉, 함수를 호출한놈이 호출당한놈의 스텍을 정리해준다. 
당한놈은 지 몸에 몇개의 인자가 들어올지 모른다. 
그래서 함수를 호출한놈이 스텍을 정리해줌. 
ex) printf, scanf 

stdcall - Win32 API의 디폴트 함수 호출 규약 
대표적으로 고정인자 함수가 이 stdcall 속한다. 
애는 피호출자가 스택을 정리한다. 

fastcall - 말그대로 빠른 함수호출규약. 

thiscall - this 포인터를 사용하는 함수들이 사용하는 함수 호출규약 ex 멤버함수. ㄷㄷ ... 

*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//wParam - 부가적인 메시지 정보를 들고 있는 변수. 키보드 관련 정보를 들고 있다. 
	//lParam - 부가적인 메시지 정보를 들고 있는 변수. 마우스 관련 정보를 들고 있다. 
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

