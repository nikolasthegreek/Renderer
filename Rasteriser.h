#pragma once
#include "Framework.h"

using namespace std;


class Rasteriser : public Framework
{
	private:
	

	public:
	
	virtual void RenderScene(HDC hdc);
	virtual void OnLButtonDown(HWND hWnd, LPARAM lParam);

};

