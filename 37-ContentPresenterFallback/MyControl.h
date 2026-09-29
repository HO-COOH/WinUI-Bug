#pragma once

#include "MyControl.g.h"
#include <winrt/Windows.UI.Xaml.Interop.h>

namespace winrt::_37_ContentPresenterFallback::implementation
{
    struct MyControl : MyControlT<MyControl>
    {
        static inline winrt::Microsoft::UI::Xaml::DependencyProperty s_property =
            winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
                L"AnotherContent",
                winrt::xaml_typename<winrt::Windows::Foundation::IInspectable>(),
                winrt::xaml_typename<class_type>(),
                nullptr);

        MyControl()
        {
            DefaultStyleKey(winrt::box_value(winrt::xaml_typename<class_type>()));
        }

		static winrt::Microsoft::UI::Xaml::DependencyProperty AnotherContentProperty()
		{
			return s_property;
		}

        winrt::Windows::Foundation::IInspectable AnotherContent()
        {
            return GetValue(s_property);
        }
    };
}

namespace winrt::_37_ContentPresenterFallback::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
