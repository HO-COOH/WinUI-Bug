// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        m_uiSettings.ColorValuesChanged([](auto...)
        {
            /*
                1. Put a break point on the line
                2. Run the app
                3. Switch to light/dark theme in windows settings

                The break point here is not hit (Tested on Windows 10 19045)
            */
            OutputDebugString(L"Color value changed\n");
        });
    }
}
