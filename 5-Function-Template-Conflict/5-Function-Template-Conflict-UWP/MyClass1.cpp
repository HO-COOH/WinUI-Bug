#include "pch.h"
#include "MyClass1.h"
#if __has_include("MyClass1.g.cpp")
#include "MyClass1.g.cpp"
#endif

namespace winrt::_5_Function_Template_Conflict_UWP::implementation
{
    winrt::hstring MyClass1::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MyClass1::MyProperty(winrt::hstring /*value*/)
    {
        throw hresult_not_implemented();
    }
}
