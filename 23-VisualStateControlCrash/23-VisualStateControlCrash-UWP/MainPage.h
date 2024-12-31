#pragma once

#include "MainPage.g.h"

namespace winrt::_23_VisualStateControlCrash_UWP::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage() = default;

        void ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
        {
            winrt::check_bool(winrt::Windows::UI::Xaml::VisualStateManager::GoToState(
                *this,
                sender.as<winrt::Windows::UI::Xaml::Controls::ComboBox>().SelectedItem().as<winrt::hstring>(),
                false
            ));
        }
        void State1Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
        {
            OutputDebugString(L"State1 clicked\n");
        }
        void State2Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
        {
            OutputDebugString(L"State2 clicked\n");
        }
    };
}

namespace winrt::_23_VisualStateControlCrash_UWP::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
