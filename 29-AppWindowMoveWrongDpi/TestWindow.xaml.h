#pragma once

#include "TestWindow.g.h"

namespace winrt::_29_AppWindowMoveWrongDpi::implementation
{
    struct TestWindow : TestWindowT<TestWindow>
    {
        TestWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::_29_AppWindowMoveWrongDpi::factory_implementation
{
    struct TestWindow : TestWindowT<TestWindow, implementation::TestWindow>
    {
    };
}
