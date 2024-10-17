#pragma once

#include "MainWindow.g.h"

namespace winrt::BindingThicknessInResourceCrash_WinUI::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            InitializeComponent();
        }

        winrt::Microsoft::UI::Xaml::Thickness MyPadding()
        {
            return { 1,2,3,4 };
        }

        winrt::Windows::UI::Color MyColor()
        {
            return winrt::Windows::UI::Colors::Red();
        }
    };
}

namespace winrt::BindingThicknessInResourceCrash_WinUI::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
