#include "pch.h"
#include "MyControl.xaml.h"
#if __has_include("MyControl.g.cpp")
#include "MyControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_26_xBindToActualThemeNoUpdate_WinUI::implementation
{
    int32_t MyControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MyControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MyControl::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
