#include "pch.h"
#include "MyControl.h"
#if __has_include("MyControl.g.cpp")
#include "MyControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::GetTemplateChildNotTriggeringReload::implementation
{
	void MyControl::OnApplyTemplate()
	{
		m_button = GetTemplateChild(L"MyButton").as<winrt::Microsoft::UI::Xaml::Controls::Button>();
		m_button.Click([this](auto&&...)
		{
				static bool IsLoaded = false;
				if (IsLoaded)
				{
					winrt::Microsoft::UI::Xaml::Markup::XamlMarkupHelper::UnloadObject(m_rect);
					m_rect = nullptr;
					m_button.Content(winrt::box_value(L"Click to load"));
				}
				else
				{
					m_rect = GetTemplateChild(L"DelayLoadRect").as<winrt::Microsoft::UI::Xaml::Shapes::Rectangle>();
					auto size = m_rect.ActualSize();
					m_rect.SizeChanged([this](auto&&...)
						{
							OutputDebugString(L"Rect loaded\n");
						});
					m_button.Content(winrt::box_value(L"Click to unload"));
				}
				IsLoaded = !IsLoaded;

		});
	}
}
