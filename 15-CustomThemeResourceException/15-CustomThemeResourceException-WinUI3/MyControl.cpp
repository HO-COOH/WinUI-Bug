#include "pch.h"
#include "MyControl.h"
#if __has_include("MyControl.g.cpp")
#include "MyControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_15_CustomThemeResourceException_WinUI3::implementation
{
    MyControl::MyControl()
    {
        DefaultStyleKey(winrt::box_value(L"_15_CustomThemeResourceException_WinUI3.MyControl"));
    }
}
