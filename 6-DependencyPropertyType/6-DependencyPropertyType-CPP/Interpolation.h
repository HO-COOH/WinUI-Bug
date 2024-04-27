#pragma once

#include "Interpolation.g.h"

namespace winrt::_6_DependencyPropertyType_CPP::implementation
{
    struct Interpolation : InterpolationT<Interpolation>
    {
        Interpolation() = default;

        static winrt::Microsoft::UI::Xaml::DependencyProperty LinearProperty();
        static void SetLinear(
            winrt::Microsoft::UI::Xaml::UIElement element,
            winrt::Microsoft::UI::Xaml::DependencyProperty value
        );
        static winrt::Microsoft::UI::Xaml::DependencyProperty GetLinear(
            winrt::Microsoft::UI::Xaml::UIElement element
        );
    };
}

namespace winrt::_6_DependencyPropertyType_CPP::factory_implementation
{
    struct Interpolation : InterpolationT<Interpolation, implementation::Interpolation>
    {
    };
}
