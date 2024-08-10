#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::LoadedNotTriggeredAfterReload_UWP::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        static bool IsLoaded = false;
        if (IsLoaded)
        {
            winrt::Windows::UI::Xaml::Markup::XamlMarkupHelper::UnloadObject(DelayLoadRect());
            myButton().Content(box_value(L"Click to load"));
        }
        else
        {
            myButton().Content(box_value(L"Click to unload"));
            auto delayLoadRect = Root().FindName(L"DelayLoadRect");
        }
        IsLoaded = !IsLoaded;
    }
    void MainPage::Rectangle_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
    }
}
