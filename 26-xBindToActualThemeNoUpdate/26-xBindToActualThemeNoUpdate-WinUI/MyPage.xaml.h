#pragma once

#include "MyPage.g.h"

namespace winrt::_26_xBindToActualThemeNoUpdate_WinUI::implementation
{
    struct MyPage : MyPageT<MyPage>
    {
        MyPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        static winrt::hstring ElementThemeToString(winrt::Microsoft::UI::Xaml::ElementTheme theme)
        {
            switch (theme)
            {
                case winrt::Microsoft::UI::Xaml::ElementTheme::Dark: return L"Dark";
                case winrt::Microsoft::UI::Xaml::ElementTheme::Light: return L"Light";
                default: return L"Default";
            }
        }
    };
}

namespace winrt::_26_xBindToActualThemeNoUpdate_WinUI::factory_implementation
{
    struct MyPage : MyPageT<MyPage, implementation::MyPage>
    {
    };
}
