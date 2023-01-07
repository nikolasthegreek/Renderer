#pragma once

#include <windows.h>
#include "resource.h"
#include "Matrix.h"

class Framework
{
public:
	Framework();
	virtual ~Framework();

	int Run(HINSTANCE hInstance, int nCmdShow);

	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	virtual void RenderScene(HDC hdc);
	virtual void OnLButtonDown(HWND hWnd, LPARAM lParam);

private:
	HINSTANCE	_hInstance;
	HWND		_hWnd;

	bool InitialiseMainWindow(int nCmdShow);
	int MainLoop();

};