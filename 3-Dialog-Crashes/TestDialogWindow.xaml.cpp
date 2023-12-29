#include "pch.h"
#include "TestDialogWindow.xaml.h"
#if __has_include("TestDialogWindow.g.cpp")
#include "TestDialogWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_3_Dialog_Crashes::implementation
{
	void TestDialogWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		Dialog().ShowAsync();
	}

}
