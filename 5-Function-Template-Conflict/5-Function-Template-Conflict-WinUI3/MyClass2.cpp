﻿#include "pch.h"
#include "MyClass2.h"
#if __has_include("MyClass2.g.cpp")
#include "MyClass2.g.cpp"
#endif

namespace winrt::_5_Function_Template_Conflict_WinUI3::implementation
{
    winrt::Windows::Foundation::IInspectable MyClass2::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MyClass2::MyProperty(winrt::Windows::Foundation::IInspectable /*value*/)
    {
        throw hresult_not_implemented();
    }
}
