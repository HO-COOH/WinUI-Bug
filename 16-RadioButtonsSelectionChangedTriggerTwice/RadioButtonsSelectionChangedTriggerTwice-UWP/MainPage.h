#pragma once

#include "MainPage.g.h"

namespace winrt::RadioButtonsSelectionChangedTriggerTwice_UWP::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);


        void RadioButtons_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
    };
}

namespace winrt::RadioButtonsSelectionChangedTriggerTwice_UWP::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
