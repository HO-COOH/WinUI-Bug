#pragma once

#include "MyControl.g.h"

namespace winrt::_15_CustomThemeResourceException_WinUI3::implementation
{
    struct MyControl : MyControlT<MyControl>
    {
        MyControl();

        winrt::hstring StringProperty() { return L""; }
        void StringProperty(winrt::hstring value)
        {
            OutputDebugString(value.data());
        }
    };
}

namespace winrt::_15_CustomThemeResourceException_WinUI3::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
