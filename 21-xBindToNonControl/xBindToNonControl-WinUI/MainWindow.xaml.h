#pragma once

#include "MainWindow.g.h"

namespace winrt::xBindToNonControl_WinUI::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow() = default;
    };
}

namespace winrt::xBindToNonControl_WinUI::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
