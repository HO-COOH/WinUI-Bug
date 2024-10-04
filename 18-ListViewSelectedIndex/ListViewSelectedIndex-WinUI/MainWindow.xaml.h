#pragma once

#include "MainWindow.g.h"

namespace winrt::ListViewSelectedIndex_WinUI::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }


        void List_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
        {
            //this prints SelectedIndex = 6
            OutputDebugString(std::format(L"Called: {}\n", List().SelectedIndex()).data());
        }
    };
}

namespace winrt::ListViewSelectedIndex_WinUI::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
