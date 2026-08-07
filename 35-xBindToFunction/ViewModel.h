#pragma once

#include "ViewModel.g.h"

namespace winrt::_35_xBindToFunction::implementation
{
    struct ViewModel : ViewModelT<ViewModel>
    {
        ViewModel() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void Print()
        {
            OutputDebugString(L"Called\n");
        }
    };
}

namespace winrt::_35_xBindToFunction::factory_implementation
{
    struct ViewModel : ViewModelT<ViewModel, implementation::ViewModel>
    {
    };
}
