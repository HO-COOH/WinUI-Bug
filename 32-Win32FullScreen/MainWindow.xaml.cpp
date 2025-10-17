#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <microsoft.ui.xaml.window.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

inline HWND GetHwnd(winrt::Microsoft::UI::Xaml::Window window)
{
    HWND hwnd{};
    window.as<IWindowNative>()->get_WindowHandle(&hwnd);
    return hwnd;
}

namespace winrt::_32_Win32FullScreen::implementation
{
    MainWindow::MainWindow()
    {
        SetHwnd(GetHwnd(*this));
    }

    winrt::fire_and_forget MainWindow::FullscreenWinUI3Button_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        Toggle();
        co_await std::chrono::seconds{ 3 };
        Toggle();
    }

    winrt::fire_and_forget MainWindow::FullscreenWin32Button_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        m_win32Window.Toggle();
        co_await std::chrono::seconds{ 3 };
        m_win32Window.Toggle();
    }
}

