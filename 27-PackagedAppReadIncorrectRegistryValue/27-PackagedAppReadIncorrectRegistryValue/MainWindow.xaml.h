#pragma once

#include "MainWindow.g.h"
#include <format>

namespace winrt::_27_PackagedAppReadIncorrectRegistryValue::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
			std::thread{ [] {
				while (true)
				{
					DWORD value;
					DWORD size = sizeof(value);
					RegGetValueW(
						HKEY_CURRENT_USER,
						LR"(Software\Microsoft\Windows\DWM)",
						L"AccentColor",
						RRF_RT_REG_DWORD,
						nullptr,
						&value,
						&size
					);
					OutputDebugString(std::format(L"{}\n", value).data());
					Sleep(1000);
				}
			} }.detach();
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::_27_PackagedAppReadIncorrectRegistryValue::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
