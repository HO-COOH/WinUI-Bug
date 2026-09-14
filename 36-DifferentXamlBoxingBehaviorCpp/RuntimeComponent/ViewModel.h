#pragma once

#include "ViewModel.g.h"

namespace winrt::RuntimeComponent::implementation
{
    struct ViewModel : ViewModelT<ViewModel>
    {
        winrt::Windows::Foundation::IInspectable EnumProperty()
        {
            return nullptr;
        }

        void EnumProperty(winrt::Windows::Foundation::IInspectable const& value)
        {
            auto className = winrt::get_class_name(value);
            auto propertyValue = value.as<winrt::Windows::Foundation::IPropertyValue>();
            auto type = propertyValue.Type();
        }
    };
}

namespace winrt::RuntimeComponent::factory_implementation
{
    struct ViewModel : ViewModelT<ViewModel, implementation::ViewModel>
    {
    };
}
