// Framework.cpp : Defines the entry point for the application.
//

#include "Framework.h"

// Reference to ourselves - primarily used to access the message handler correctly
Framework *	_thisFramework = NULL;

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

// The entry point for a Windows application
int APIENTRY wWinMain(_In_	   HINSTANCE hInstance,
				  	  _In_opt_ HINSTANCE hPrevInstance,
					  _In_	   LPWSTR    lpCmdLine,
					  _In_	   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	if (_thisFramework)
	{
		return _thisFramework->Run(hInstance, nCmdShow);
	}
	return -1;
}


Framework::Framework()
{
	_thisFramework = this;
}

Framework::~Framework()
{
}

int Framework::Run(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;
	if (!InitialiseMainWindow(nCmdShow))
	{
		return -1;
	}
	return MainLoop();
}

int Framework::MainLoop()
{
	MSG msg;

	HACCEL hAccelTable = LoadAccelerators(_hInstance, MAKEINTRESOURCE(IDC_RASTERISER));

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}

bool Framework::InitialiseMainWindow(int nCmdShow)
{
	#define MAX_LOADSTRING 100

	WCHAR windowTitle[MAX_LOADSTRING];          
	WCHAR windowClass[MAX_LOADSTRING];            
	
	LoadStringW(_hInstance, IDS_APP_TITLE, windowTitle, MAX_LOADSTRING);
	LoadStringW(_hInstance, IDC_RASTERISER, windowClass, MAX_LOADSTRING);

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_RASTERISER));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = windowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	if (!RegisterClassExW(&wcex))
	{
		return false;
	}

	_hWnd = CreateWindowW(windowClass, 
						  windowTitle, 
					      WS_OVERLAPPEDWINDOW,
						  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
					      nullptr, nullptr, _hInstance, nullptr);
	if (!_hWnd)
	{
		return false;
	}

	//=== Add code on Window Initialization ====
	

	//=== Show Window ====

	ShowWindow(_hWnd, nCmdShow);
	UpdateWindow(_hWnd);

	return true;
}


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (_thisFramework != NULL)
	{
		// If framework is started, then we can call our own message proc
		return _thisFramework->MsgProc(hWnd, message, wParam, lParam);
	}
	else
	{
		// otherwise, we just pass control to the default message proc
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

LRESULT Framework::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			
			//=== Add code for Rendering Models);
			RenderScene(hdc);

			EndPaint(hWnd, &ps);
		}
		break;

		case WM_LBUTTONDOWN:
			//OnLButtonDown(hWnd, lParam);
			break;

		case WM_LBUTTONUP:
			//OnLButtonUp(hWnd, lParam);
			break;

		case WM_MOUSEMOVE:
			//OnMouseMove(hWnd, lParam);
			break;
			

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


void Framework::RenderScene(HDC hdc)
{
}

void Framework::OnLButtonDown(HWND hWnd, LPARAM lParam)
{
}

