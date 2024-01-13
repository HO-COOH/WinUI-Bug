#pragma once

#include "MainWindow.g.h"
#include "TestDialogWindow.g.h"

namespace winrt::_3_Dialog_Crashes::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            TestDialogWindow{}.Activate();
        }
    };
}

namespace winrt::_3_Dialog_Crashes::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
