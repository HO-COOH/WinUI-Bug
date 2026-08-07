#pragma once

#include "MainWindow.g.h"

namespace winrt::_35_xBindToFunction::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
    };
}

namespace winrt::_35_xBindToFunction::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
