#pragma once

#include "MyClass2.g.h"

namespace winrt::_5_Function_Template_Conflict_WinUI3::implementation
{
    struct MyClass2 : MyClass2T<MyClass2>
    {
        MyClass2() = default;

        winrt::Windows::Foundation::IInspectable MyProperty();
        void MyProperty(winrt::Windows::Foundation::IInspectable value);
    };
}

namespace winrt::_5_Function_Template_Conflict_WinUI3::factory_implementation
{
    struct MyClass2 : MyClass2T<MyClass2, implementation::MyClass2>
    {
    };
}
