#pragma once

#include "App.xaml.g.h"

namespace winrt::_28_CannotUseInt32AsDataType::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
