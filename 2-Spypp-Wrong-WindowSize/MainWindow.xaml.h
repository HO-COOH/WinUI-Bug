#pragma once

#include "MainWindow.g.h"
#include <winrt/Microsoft.UI.Windowing.h>

namespace winrt::_2_Spypp_Wrong_WindowSize::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            AppWindow().Resize({ .Width = 2000, .Height = 2000 });
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::_2_Spypp_Wrong_WindowSize::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
