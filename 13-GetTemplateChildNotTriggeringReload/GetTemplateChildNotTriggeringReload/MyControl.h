#pragma once

#include "MyControl.g.h"

namespace winrt::GetTemplateChildNotTriggeringReload::implementation
{
    struct MyControl : MyControlT<MyControl>
    {
        MyControl() = default;

        void OnApplyTemplate();
    private:
        winrt::Microsoft::UI::Xaml::Controls::Button m_button{ nullptr };
        winrt::Microsoft::UI::Xaml::Shapes::Rectangle m_rect{ nullptr };
    };
}

namespace winrt::GetTemplateChildNotTriggeringReload::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
