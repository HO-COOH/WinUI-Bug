#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Input.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <microsoft.ui.xaml.window.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::InputNonClientPointerSourceWithCustomTitlebar::implementation
{
    MainWindow::MainWindow()
    {
        ExtendsContentIntoTitleBar(true);
        auto presenter = AppWindow().Presenter().as<winrt::Microsoft::UI::Windowing::OverlappedPresenter>();
        presenter.SetBorderAndTitleBar(false, false);

        auto windowNative{ this->m_inner.as<::IWindowNative>() };
        HWND hwnd{ 0 };
        windowNative->get_WindowHandle(&hwnd);
        auto source = winrt::Microsoft::UI::Input::InputNonClientPointerSource::GetForWindowId(winrt::Microsoft::UI::GetWindowIdFromWindow(hwnd));
        source.ClearRegionRects(winrt::Microsoft::UI::Input::NonClientRegionKind::Caption);
        source.SetRegionRects(
            winrt::Microsoft::UI::Input::NonClientRegionKind::Caption,
            {
                winrt::Windows::Graphics::RectInt32{
                    .X = (int)0,
                    .Y = (int)0,
                    .Width = (int)400,
                    .Height = (int)400
                }
            }
        );
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
