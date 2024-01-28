#include "pch.h"
#include "GroupedData.h"
#if __has_include("GroupedData.g.cpp")
#include "GroupedData.g.cpp"
#endif

namespace winrt::_3_CollectionViewSource_CppUWP::implementation
{
	winrt::hstring GroupedData::Title()
	{
		return m_title;
	}
	void GroupedData::Title(winrt::hstring value)
	{
		m_title = value;
	}
	winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> GroupedData::data()
	{
		return m_data;
	}
	void GroupedData::data(winrt::Windows::Foundation::Collections::IObservableVector<winrt::hstring> value)
	{
		m_data = value;
	}
}
