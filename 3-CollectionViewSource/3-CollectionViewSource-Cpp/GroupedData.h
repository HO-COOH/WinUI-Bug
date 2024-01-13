#pragma once

#include "GroupedData.g.h"

namespace winrt::_3_CollectionViewSource_Cpp::implementation
{
    struct GroupedData : GroupedDataT<GroupedData>
    {
        GroupedData() = default;

        winrt::hstring Title();
        void Title(winrt::hstring value);

        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> data();
        void data(winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> value);

    private:
        winrt::hstring m_title = L"Title";
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> m_data = winrt::single_threaded_observable_vector<winrt::hstring>();
    };
}

namespace winrt::_3_CollectionViewSource_Cpp::factory_implementation
{
    struct GroupedData : GroupedDataT<GroupedData, implementation::GroupedData>
    {
    };
}
