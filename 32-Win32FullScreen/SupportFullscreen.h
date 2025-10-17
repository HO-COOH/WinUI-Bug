#pragma once

class SupportFullScreen
{
	HWND m_hwnd;
	WINDOWPLACEMENT m_placement;
	bool m_isFullScreen = false;

	void SetFullscreen();
	void ExitFullscreen();
public:
	void SetHwnd(HWND hwnd);

	void Toggle();
};
