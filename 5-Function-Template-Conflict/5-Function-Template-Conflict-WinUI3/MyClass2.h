#pragma once

#include "MyClass2.g.h"

namespace winrt::_5_Function_Template_Conflict_WinUI3::implementation
{
    struct MyClass2 : MyClass2T<MyClass2>
    {
        MyClass2() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::_5_Function_Template_Conflict_WinUI3::factory_implementation
{
    struct MyClass2 : MyClass2T<MyClass2, implementation::MyClass2>
    {
    };
}
