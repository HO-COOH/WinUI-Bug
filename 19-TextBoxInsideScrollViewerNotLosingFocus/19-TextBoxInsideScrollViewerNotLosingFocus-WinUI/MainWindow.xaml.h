#pragma once

#include "MainWindow.g.h"

namespace winrt::_19_TextBoxInsideScrollViewerNotLosingFocus_WinUI::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow() = default;
    };
}

namespace winrt::_19_TextBoxInsideScrollViewerNotLosingFocus_WinUI::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
