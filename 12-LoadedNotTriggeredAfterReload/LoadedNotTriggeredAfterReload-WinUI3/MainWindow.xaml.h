#pragma once

#include "MainWindow.g.h"

namespace winrt::LoadedNotTriggeredAfterReload_WinUI3::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);


    };
}

namespace winrt::LoadedNotTriggeredAfterReload_WinUI3::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
