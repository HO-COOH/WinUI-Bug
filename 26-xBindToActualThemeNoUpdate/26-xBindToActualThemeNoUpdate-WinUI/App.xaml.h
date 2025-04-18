#pragma once

#include "App.xaml.g.h"

namespace winrt::_26_xBindToActualThemeNoUpdate_WinUI::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
