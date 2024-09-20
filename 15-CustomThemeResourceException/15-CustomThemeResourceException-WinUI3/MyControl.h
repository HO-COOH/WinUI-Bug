#pragma once

#include "MyControl.g.h"
#include <winrt/Windows.UI.Xaml.Interop.h>

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
  
        //inline static winrt::Microsoft::UI::Xaml::DependencyProperty s_stringPropertyProperty = 
        //    winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
        //    L"StringProperty",
        //    winrt::xaml_typename<winrt::hstring>(),
        //    winrt::xaml_typename<class_type>(),
        //    nullptr
        //);
        //static winrt::Microsoft::UI::Xaml::DependencyProperty StringPropertyProperty()
        //{
        //    return s_stringPropertyProperty;
        //}

        /*------------------Uncomment this, it will cause exception--------------*/
        static winrt::Microsoft::UI::Xaml::DependencyProperty StringPropertyProperty()
        {
            static auto s_stringPropertyProperty =
                winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
                    L"StringProperty",
                    winrt::xaml_typename<winrt::hstring>(),
                    winrt::xaml_typename<class_type>(),
                    nullptr
                );
            return s_stringPropertyProperty;
        }
    };
}

namespace winrt::_15_CustomThemeResourceException_WinUI3::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
