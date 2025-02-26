#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <microsoft.ui.xaml.window.h>
#include <winrt/Microsoft.UI.Input.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
static HWND CreateWin32Window()
{
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc; // Pointer to the window procedure
    wc.lpszClassName = CLASS_NAME; // Window class name

    // Register the window class
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        L"Sample Window",                // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window
        NULL,       // Menu
        NULL,  // Instance handle
        NULL        // Additional application data
    );
    ShowWindow(hwnd, SW_SHOW);
    return hwnd;
}

namespace winrt::_25_NonClientRegionChangedSilently::implementation
{
    static auto GetHwnd(winrt::Microsoft::UI::Xaml::Window const& window)
    {
        HWND hwnd;
        window.as<IWindowNative>()->get_WindowHandle(&hwnd);
        return hwnd;
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));

        //ExtendsContentIntoTitleBar(true);
        auto hwnd = CreateWin32Window();
        auto windowId = winrt::Microsoft::UI::GetWindowIdFromWindow(hwnd);
        auto appWindow = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);
        appWindow.TitleBar().ExtendsContentIntoTitleBar(true);
        auto presenter = appWindow.Presenter().as<winrt::Microsoft::UI::Windowing::OverlappedPresenter>();
        auto pointerSource = winrt::Microsoft::UI::Input::InputNonClientPointerSource::GetForWindowId(windowId);
        pointerSource.SetRegionRects(
            winrt::Microsoft::UI::Input::NonClientRegionKind::Maximize,
            {
                winrt::Windows::Graphics::RectInt32
                {
                    .X = 0,
                    .Y = 0,
                    .Width = 100,
                    .Height = 100
                }
            }
        );

        pointerSource.RegionsChanged([](
            winrt::Microsoft::UI::Input::InputNonClientPointerSource const& source, 
            winrt::Microsoft::UI::Input::NonClientRegionsChangedEventArgs const& arg)
            {
                if (auto regions = arg.ChangedRegions(); 
                    std::ranges::find(regions, winrt::Microsoft::UI::Input::NonClientRegionKind::Maximize) != regions.end())
                {
                    auto changedRegions = source.GetRegionRects(winrt::Microsoft::UI::Input::NonClientRegionKind::Maximize);
                    for (auto region : changedRegions)
                    {
                        OutputDebugString(std::format(L"X: {}, Y: {}, Width: {}, Height: {}\n", region.X, region.Y, region.Width, region.Height).data());
                    }
                }
            });
    }
}
