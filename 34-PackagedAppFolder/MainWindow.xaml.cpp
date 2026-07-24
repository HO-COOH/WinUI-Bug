#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <wil/com.h>
#include <wil/win32_helpers.h>
#include <array>
#include <appmodel.h>
#include <filesystem>
#include <ShlObj_core.h>
#include <winrt/Windows.Storage.h>
#pragma comment(lib, "shell32.lib")

namespace winrt::_34_PackagedAppFolder::implementation
{
	static std::filesystem::path GetLocalDataFolder()
	{
		wil::unique_cotaskmem_string localAppData;
		SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, localAppData.put());

		std::array<wchar_t, PACKAGE_FAMILY_NAME_MAX_LENGTH + 1> familyName;
		UINT32 bufferSize = familyName.size();
		GetCurrentPackageFamilyName(&bufferSize, familyName.data());

		return std::filesystem::path{ localAppData.get() } / std::format(LR"(packages\{}\LocalCache\Local)", familyName.data());
	}

	static std::filesystem::path GetLocalDataFolder2()
	{
		return std::filesystem::path{ winrt::Windows::Storage::ApplicationData::Current().LocalCacheFolder().Path().c_str() } / L"Local";
	}

	void MainWindow::Files_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		std::vector<winrt::Windows::Foundation::IInspectable> result;
		for (auto file : std::filesystem::directory_iterator{ GetLocalDataFolder2() })
		{
			result.push_back(winrt::box_value(file.path().wstring()));
		}
		sender.as<winrt::Microsoft::UI::Xaml::Controls::ListView>().ItemsSource(winrt::single_threaded_vector(std::move(result)));
	}

}
