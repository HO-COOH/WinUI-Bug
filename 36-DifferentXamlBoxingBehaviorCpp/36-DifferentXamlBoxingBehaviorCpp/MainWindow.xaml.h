#pragma once

#include "MainWindow.g.h"

namespace winrt::_36_DifferentXamlBoxingBehaviorCpp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {

    };
}

namespace winrt::_36_DifferentXamlBoxingBehaviorCpp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
