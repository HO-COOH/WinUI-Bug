#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <format>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::RadioButtonsSelectionChangedTriggerTwice_UWP::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::RadioButtons_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
    {
        static int i = 0;
        OutputDebugString(std::format(L"#{}: Selection changed\n", i++).data());
    }

}
