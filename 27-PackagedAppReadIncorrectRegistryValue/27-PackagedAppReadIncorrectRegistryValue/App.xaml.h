#pragma once

#include "App.xaml.g.h"

namespace winrt::_27_PackagedAppReadIncorrectRegistryValue::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
