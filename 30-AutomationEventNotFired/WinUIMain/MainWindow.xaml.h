#pragma once

#include "MainWindow.g.h"

namespace winrt::WinUIMain::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow() = default;

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinUIMain::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
