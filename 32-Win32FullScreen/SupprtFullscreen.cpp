#include "pch.h"
#include "SupportFullscreen.h"


void SupportFullScreen::SetHwnd(HWND hwnd)
{
	m_hwnd = hwnd;
}

void SupportFullScreen::SetFullscreen()
{
    DWORD dwStyle = GetWindowLong(m_hwnd, GWL_STYLE);
    MONITORINFO mi = { .cbSize = sizeof(mi) };
    if (GetWindowPlacement(m_hwnd, &m_placement) &&
        GetMonitorInfo(MonitorFromWindow(m_hwnd, MONITOR_DEFAULTTOPRIMARY), &mi)
    ) 
    {
        SetWindowLong(m_hwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
        SetWindowPos(m_hwnd, 
            HWND_TOP,
            mi.rcMonitor.left, mi.rcMonitor.top,
            mi.rcMonitor.right - mi.rcMonitor.left,
            mi.rcMonitor.bottom - mi.rcMonitor.top,
            SWP_NOOWNERZORDER | SWP_FRAMECHANGED
        );
    }
}

void SupportFullScreen::ExitFullscreen()
{
    DWORD dwStyle = GetWindowLong(m_hwnd, GWL_STYLE);
    SetWindowLong(m_hwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
    SetWindowPlacement(m_hwnd, &m_placement);
    SetWindowPos(
        m_hwnd, 
        NULL, 
        0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
}

void SupportFullScreen::Toggle()
{
    m_isFullScreen ? ExitFullscreen() : SetFullscreen();
    m_isFullScreen = !m_isFullScreen;
}
