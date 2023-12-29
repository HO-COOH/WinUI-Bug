#pragma once

#include "TestDialogWindow.g.h"

namespace winrt::_3_Dialog_Crashes::implementation
{
    struct TestDialogWindow : TestDialogWindowT<TestDialogWindow>
    {
        TestDialogWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::_3_Dialog_Crashes::factory_implementation
{
    struct TestDialogWindow : TestDialogWindowT<TestDialogWindow, implementation::TestDialogWindow>
    {
    };
}
