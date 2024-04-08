# WinUI-Bug
A repo dedicated for reproducing uwp/windows app sdk bugs

|Issue|Description|Last checked|Fixed?
|---|---|---|---|
|[UISettings-ColorValueChanged](https://github.com/microsoft/WindowsAppSDK/issues/4006)|`UISettings.ColorValueChanged` not working in WinUI3 (packaged) apps.|WASDK 1.5| :x:
|[Spypp-Wrong-WindowSize](https://developercommunity.visualstudio.com/t/spy-gives-wrong-window-size/10537664?scope=follow)|Spy++ returns wrong window size. | / | :x:
|[Dialog-Crashes](https://github.com/microsoft/microsoft-ui-xaml/issues/8913)|WinUI3 App crash when closing an inactive window with a `ContentDialog` opened| WASDK 1.5| :x:
|[CollectionViewSource not working](https://github.com/microsoft/microsoft-ui-xaml/issues/6619)|`CollectionViewSource` not working with C# public fields and C++WinRT| UWP & WASDK 1.5 | C++ :white_check_mark: C# :x:
|[Same Property name with different type conflict](https://github.com/microsoft/microsoft-ui-xaml/issues/9419)|Two `runtimeclass` with properties that has the same name but different type will fail to build (this issue only relates to C++) | UWP & WASDK 1.5.2 | UWP :x: WinUI3 :white_check_mark: