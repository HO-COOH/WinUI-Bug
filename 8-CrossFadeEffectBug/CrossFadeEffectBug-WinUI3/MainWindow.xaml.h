#pragma once

#include "MainWindow.g.h"

namespace winrt::CrossFadeEffectBug_WinUI3::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow() = default;
        void Border_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e);
    };
}

namespace winrt::CrossFadeEffectBug_WinUI3::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
