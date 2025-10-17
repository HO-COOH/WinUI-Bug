#pragma once

#include "MainWindow.g.h"
#include "MyWindow.h"

namespace winrt::_32_Win32FullScreen::implementation
{
    struct MainWindow : MainWindowT<MainWindow>, SupportFullScreen
    {
        MyWindow m_win32Window;

        MainWindow();

        winrt::fire_and_forget FullscreenWinUI3Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        winrt::fire_and_forget FullscreenWin32Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::_32_Win32FullScreen::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
