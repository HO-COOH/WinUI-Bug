#pragma once
#include <wil/resource.h>
#include <string_view>
#include "SupportFullscreen.h"

class MyWindow : public SupportFullScreen
{
	wil::unique_hwnd m_hwnd;
public:
	MyWindow(
		std::wstring_view windowName = L"MyWindow", 
		DWORD exStyle = 0, 
		DWORD style = WS_OVERLAPPEDWINDOW, 
		int x = CW_USEDEFAULT, 
		int y = CW_USEDEFAULT, 
		int cx = CW_USEDEFAULT, 
		int cy = CW_USEDEFAULT
	);

	HWND Get() const
	{
		return m_hwnd.get();
	}
};
