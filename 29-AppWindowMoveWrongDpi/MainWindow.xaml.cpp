#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.UI.Windowing.h>
#include "WindowUtils.hpp"
#include <ShellScalingApi.h>
#pragma comment(lib, "shcore.lib")

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_29_AppWindowMoveWrongDpi::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }


    void MainWindow::MonitorLists_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        winrt::check_bool(EnumDisplayMonitors(
            nullptr,
            nullptr,
            +[](HMONITOR hMonitor, HDC /* hdc */, LPRECT /* lprcMonitor */, LPARAM dwData) -> BOOL
            {
                auto monitors = reinterpret_cast<std::vector<HMONITOR>*>(dwData);
                monitors->push_back(hMonitor);
                return TRUE;
            },
            reinterpret_cast<LPARAM>(&monitors)
        ));

		//add a button for each monitor, and a click handler that center a window on that monitor
        for (auto monitor : monitors)
        {
            auto button = Microsoft::UI::Xaml::Controls::Button();
            button.Content(winrt::box_value(L"Center"));
            button.Click({ this, &MainWindow::OnMonitorButtonClick });
            MonitorLists().Items().Append(button);
		}
        testWindow.Activate();
    }

    void MainWindow::OnMonitorButtonClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto button = sender.as<winrt::Microsoft::UI::Xaml::Controls::Button>();
        uint32_t index{};
        MonitorLists().Items().IndexOf(button, index);

		MONITORINFO info = { sizeof(MONITORINFO) };
		winrt::check_bool(GetMonitorInfo(monitors[index], &info));

		auto appWindow = testWindow.AppWindow();
        auto hwnd = GetHwnd(testWindow);
        UINT dpi, dpiY;
        winrt::check_hresult(GetDpiForMonitor(monitors[index], MDT_EFFECTIVE_DPI, &dpi, &dpiY));
        winrt::Windows::Graphics::SizeInt32 windowSize{ ScaleForDpi<int>(1000, dpi), ScaleForDpi<int>(133, dpi) };
        appWindow.MoveAndResize(winrt::Windows::Graphics::RectInt32{
            .X = info.rcWork.left + (info.rcWork.right - info.rcWork.left - windowSize.Width) / 2,
            .Y = info.rcWork.top,
            .Width = windowSize.Width,
            .Height = windowSize.Height
        });
    }
}
