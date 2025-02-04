#pragma once

#include "MainWindow.g.h"

namespace winrt::InputNonClientPointerSourceWithCustomTitlebar::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::InputNonClientPointerSourceWithCustomTitlebar::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
