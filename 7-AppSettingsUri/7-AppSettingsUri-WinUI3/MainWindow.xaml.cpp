#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.System.h>
#include <winrt/Windows.ApplicationModel.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_7_AppSettingsUri_WinUI3::implementation
{
    void MainWindow::myButton_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        winrt::Windows::System::Launcher::LaunchUriAsync(
            winrt::Windows::Foundation::Uri{ L"ms-settings:appsfeatures-app" }
        );
    }

    void MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        winrt::Windows::System::LauncherOptions options;
        options.TargetApplicationPackageFamilyName(winrt::Windows::ApplicationModel::Package::Current().Id().FamilyName());
        winrt::Windows::System::Launcher::LaunchUriAsync(
            winrt::Windows::Foundation::Uri{ L"ms-settings:appsfeatures-app" },
            options
        );
    }

    void MainWindow::Button_Click_1(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        winrt::Windows::System::LauncherOptions options;
        options.TargetApplicationPackageFamilyName(FamilyNameTextBox().Text());
        winrt::Windows::System::Launcher::LaunchUriAsync(
            winrt::Windows::Foundation::Uri{ L"ms-settings:appsfeatures-app" },
            options);
    }

}
