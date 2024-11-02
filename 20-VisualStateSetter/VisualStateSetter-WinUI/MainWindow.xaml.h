#pragma once

#include "MainWindow.g.h"

namespace winrt::VisualStateSetter_WinUI::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        static bool IsOn(winrt::Windows::Foundation::IReference<bool> v)
        {
            return v ? v.GetBoolean() : false;
        }
    };
}

namespace winrt::VisualStateSetter_WinUI::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
