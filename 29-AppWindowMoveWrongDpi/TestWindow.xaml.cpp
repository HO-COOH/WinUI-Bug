#include "pch.h"
#include "TestWindow.xaml.h"
#if __has_include("TestWindow.g.cpp")
#include "TestWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_29_AppWindowMoveWrongDpi::implementation
{
    int32_t TestWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TestWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
