#pragma once

#include "App.xaml.g.h"
#include "MyControl.h"

namespace winrt::GetTemplateChildNotTriggeringReload::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
