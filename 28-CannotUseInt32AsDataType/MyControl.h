#pragma once

#include "MyControl.g.h"

namespace winrt::_28_CannotUseInt32AsDataType::implementation
{
    struct MyControl : MyControlT<MyControl>
    {
        MyControl() = default;

        winrt::Windows::Foundation::Collections::IObservableVector<int> Items()
        {
            return winrt::single_threaded_observable_vector<int>({ 1,2,3 });
        }
    };
}

namespace winrt::_28_CannotUseInt32AsDataType::factory_implementation
{
    struct MyControl : MyControlT<MyControl, implementation::MyControl>
    {
    };
}
