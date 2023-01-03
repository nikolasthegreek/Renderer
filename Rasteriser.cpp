#include "Rasteriser.h"

Rasteriser app;

//=== Implementations of Rasterizer behaviour ===


void Rasteriser::RenderScene(HDC hdc)
{
	//=== Add Code for Rendering something =====
	RECT	 _rect;
	COLORREF _colour;

	_rect.left = 100;
	_rect.top = 200;
	_rect.right = 300;
	_rect.bottom = 300;
	_colour = RGB(rand() % 256, rand() % 256, rand() % 256);
	
	HBRUSH brush = CreateSolidBrush(_colour);
	FillRect(hdc, &_rect, brush);
	DeleteObject(brush);

}

void Rasteriser::OnLButtonDown(HWND hWnd, LPARAM lParam)
{
	//=== Add Code of what happens in Mouse Left Button is down =====


}
