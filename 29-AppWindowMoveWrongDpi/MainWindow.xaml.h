#pragma once

#include "MainWindow.g.h"

namespace winrt::_29_AppWindowMoveWrongDpi::implementation
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
        void MonitorLists_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void OnMonitorButtonClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        std::vector<HMONITOR> monitors;
        winrt::_29_AppWindowMoveWrongDpi::TestWindow testWindow;
    };
}

namespace winrt::_29_AppWindowMoveWrongDpi::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
