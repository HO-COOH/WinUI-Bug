#include "pch.h"
#include "Interpolation.h"
#if __has_include("Interpolation.g.cpp")
#include "Interpolation.g.cpp"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>

namespace winrt::_6_DependencyPropertyType_CPP::implementation
{
    winrt::Microsoft::UI::Xaml::DependencyProperty Interpolation::LinearProperty()
    {
        static auto s_linearProperty =
            winrt::Microsoft::UI::Xaml::DependencyProperty::RegisterAttached(
                L"Linear",
                winrt::xaml_typename<winrt::Microsoft::UI::Xaml::DependencyProperty>(),
                winrt::xaml_typename<class_type>(),
                { nullptr }
        );
        return s_linearProperty;
    }
    void Interpolation::SetLinear(winrt::Microsoft::UI::Xaml::UIElement element, winrt::Microsoft::UI::Xaml::DependencyProperty value)
    {
        element.SetValue(LinearProperty(), value);
    }
    winrt::Microsoft::UI::Xaml::DependencyProperty Interpolation::GetLinear(winrt::Microsoft::UI::Xaml::UIElement element)
    {
        return element.GetValue(LinearProperty()).as<winrt::Microsoft::UI::Xaml::DependencyProperty>();
    }
}
