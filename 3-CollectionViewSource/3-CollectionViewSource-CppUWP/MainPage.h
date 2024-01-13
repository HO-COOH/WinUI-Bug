#pragma once

#include "MainPage.g.h"

namespace winrt::_3_CollectionViewSource_CppUWP::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            _3_CollectionViewSource_CppUWP::GroupedData data;
            data.data().Append(L"obj1");
            data.data().Append(L"obj2");
            data.data().Append(L"obj3");
            m_groups.Append(data);
        }
        winrt::Windows::Foundation::Collections::IObservableVector<_3_CollectionViewSource_CppUWP::GroupedData> groups() { return m_groups; }
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<_3_CollectionViewSource_CppUWP::GroupedData> m_groups = winrt::single_threaded_observable_vector<_3_CollectionViewSource_CppUWP::GroupedData>();
    };
}

namespace winrt::_3_CollectionViewSource_CppUWP::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
