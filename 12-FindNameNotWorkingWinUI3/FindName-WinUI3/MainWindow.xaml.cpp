#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::FindName_WinUI3::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        static bool IsLoaded = false;
        if (IsLoaded)
        {
            winrt::Microsoft::UI::Xaml::Markup::XamlMarkupHelper::UnloadObject(DelayLoadRect());
            myButton().Content(box_value(L"Click to load"));
        }
        else
        {
            myButton().Content(box_value(L"Click to unload"));
            auto delayLoadRect = Root().FindName(L"DelayLoadRect");
        }
        IsLoaded = !IsLoaded;
    }

    void MainWindow::Rectangle_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        winrt::Microsoft::UI::Xaml::Controls::ContentDialog dialog;
        dialog.XamlRoot(Content().XamlRoot());
        dialog.Title(winrt::box_value(L"Loaded"));
        dialog.PrimaryButtonText(L"OK");
        dialog.ShowAsync();
    }
}
