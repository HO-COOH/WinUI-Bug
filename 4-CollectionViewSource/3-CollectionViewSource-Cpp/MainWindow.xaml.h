#pragma once

#include "MainWindow.g.h"
#include "GroupedData.g.h"

namespace winrt::_3_CollectionViewSource_Cpp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            _3_CollectionViewSource_Cpp::GroupedData data;
            data.data().Append(L"obj1");
            data.data().Append(L"obj2");
            data.data().Append(L"obj3");
            m_groups.Append(data);
        }

        winrt::Windows::Foundation::Collections::IObservableVector<_3_CollectionViewSource_Cpp::GroupedData> groups() { return m_groups; }
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<_3_CollectionViewSource_Cpp::GroupedData> m_groups = winrt::single_threaded_observable_vector<_3_CollectionViewSource_Cpp::GroupedData>();
    };
}

namespace winrt::_3_CollectionViewSource_Cpp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
