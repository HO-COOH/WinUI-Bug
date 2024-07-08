#include "pch.h"


int main()
{
    winrt::init_apartment();

    winrt::Windows::Foundation::Uri uri{ LR"(myapp://open?file="C:/我.txt")" };
    winrt::Windows::Foundation::WwwFormUrlDecoder parsed{ uri.Query() };
    for (auto entry : parsed)
    {
        std::wcout << entry.Name().data() << L'\t' << entry.Value().data() << L'\n';
    }
}
