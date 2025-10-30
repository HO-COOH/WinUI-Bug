#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <format>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::_33_TeachingTipNullContent::implementation
{
	static void printVisualTree(winrt::Microsoft::UI::Xaml::FrameworkElement const& element)
	{
		if (!element)
			return;

		OutputDebugString(std::format(L"{}: {}\n", winrt::get_class_name(element), element.Name()).data());

		auto const numChild = winrt::Microsoft::UI::Xaml::Media::VisualTreeHelper::GetChildrenCount(element);
		for (auto i = 0; i < numChild; ++i)
		{
			printVisualTree(winrt::Microsoft::UI::Xaml::Media::VisualTreeHelper::GetChild(element, i).as<winrt::Microsoft::UI::Xaml::FrameworkElement>());
		}
	}
	void MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		MyTip().IsOpen(true);
	}

	void MainWindow::MyTip_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		auto teachingTip = sender.as<winrt::Microsoft::UI::Xaml::Controls::TeachingTip>();
		OutputDebugString(L"==============Loaded==========\n");
		printVisualTree(teachingTip);
	}

	void MainWindow::MyTip_LayoutUpdated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::Foundation::IInspectable const& e)
	{
		OutputDebugString(L"==============Layout Updated==========\n");
		printVisualTree(MyTip());
	}

}

