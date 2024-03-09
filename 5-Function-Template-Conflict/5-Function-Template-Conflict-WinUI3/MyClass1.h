﻿#pragma once

#include "MyClass1.g.h"

namespace winrt::_5_Function_Template_Conflict_WinUI3::implementation
{
    struct MyClass1 : MyClass1T<MyClass1>
    {
        MyClass1() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::_5_Function_Template_Conflict_WinUI3::factory_implementation
{
    struct MyClass1 : MyClass1T<MyClass1, implementation::MyClass1>
    {
    };
}
