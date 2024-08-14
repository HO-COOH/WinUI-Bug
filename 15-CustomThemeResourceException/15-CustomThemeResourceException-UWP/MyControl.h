#pragma once

#include "MyControl.g.h"

namespace winrt::_15_CustomThemeResourceException_UWP::implementation
{
    struct MyControl : MyControlT<MyControl>
    {
        MyControl() = default;

        winrt::hstring StringProperty() { return L""; }
        void StringProperty(winrt::hstring value)
        {
            OutputDebugString(value.data());
        }
    };
}

namespace winrt::_15_CustomThemeResourceException_UWP::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
