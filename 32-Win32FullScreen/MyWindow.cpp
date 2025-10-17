#include "pch.h"
#include "MyWindow.h"


static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


MyWindow::MyWindow(std::wstring_view windowName, DWORD exStyle, DWORD style, int x, int y, int cx, int cy)
{
	static auto registered = []() {
		WNDCLASS wc
		{
			.style = CS_HREDRAW | CS_VREDRAW,
			.lpfnWndProc = WndProc,
			.cbWndExtra = sizeof(void*),
			.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND),
			.lpszClassName = L"MyWindowClass",
		};
		RegisterClass(&wc);
		return wc;
		}();

	auto const hwnd = CreateWindowExW(
		exStyle,
		L"MyWindowClass",
		windowName.data(),
		style,
		x,
		y,
		cx,
		cy,
		nullptr,
		nullptr,
		nullptr,
		this
	);
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	SetHwnd(hwnd);

	ShowWindow(hwnd, SW_SHOW);
	m_hwnd.reset(hwnd);
}
