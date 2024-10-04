#pragma once

#include "MyListView.g.h"
#include <format>

namespace winrt::ListViewSelectedIndex_WinUI::implementation
{
    struct MyListView : MyListViewT<MyListView>
    {
        MyListView()
        {
            SelectionChanged({ this, &MyListView::onSelectedIndexChanged });
        }

        void OnApplyTemplate()
        {
            //this prints SelectedIndex = 6
            OutputDebugString(std::format(L"Called: {}\n", SelectedIndex()).data());
        }

        void onSelectedIndexChanged(
            winrt::Windows::Foundation::IInspectable const&, 
            winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const&)
        {
            //this prints SelectedIndex = 6
            OutputDebugString(std::format(L"Called: {}\n", SelectedIndex()).data());
        }
    };
}

namespace winrt::ListViewSelectedIndex_WinUI::factory_implementation
{
    struct MyListView : MyListViewT<MyListView, implementation::MyListView>
    {
    };
}
