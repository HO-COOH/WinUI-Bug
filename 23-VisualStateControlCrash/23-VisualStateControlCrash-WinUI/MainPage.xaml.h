#pragma once

#include "MainPage.g.h"

namespace winrt::_23_VisualStateControlCrash_WinUI::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
        {
            winrt::check_bool(winrt::Microsoft::UI::Xaml::VisualStateManager::GoToState(
                *this,
                sender.as<winrt::Microsoft::UI::Xaml::Controls::ComboBox>().SelectedItem().as<winrt::hstring>(),
                false
            ));
        }
        void State1Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
        {
            OutputDebugString(L"State1 clicked\n");
        }
        void State2Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
        {
            OutputDebugString(L"State2 clicked\n");
        }
    };
}

namespace winrt::_23_VisualStateControlCrash_WinUI::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
