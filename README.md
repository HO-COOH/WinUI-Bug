# WinUI-Bug
A repo dedicated for reproducing uwp/windows app sdk bugs

|Issue|Description|Last checked|Fixed?
|---|---|---|---|
|[UISettings-ColorValueChanged](https://github.com/microsoft/WindowsAppSDK/issues/4006)|`UISettings.ColorValueChanged` not working in WinUI3 (packaged) apps.|WASDK 1.5| :x:
|[Spypp-Wrong-WindowSize](https://developercommunity.visualstudio.com/t/spy-gives-wrong-window-size/10537664?scope=follow)|Spy++ returns wrong window size. | / | :x:
|[Dialog-Crashes](https://github.com/microsoft/microsoft-ui-xaml/issues/8913)|WinUI3 App crash when closing an inactive window with a `ContentDialog` opened| 1.6.240531000-experimental1| :white_check_mark:
|[CollectionViewSource not working](https://github.com/microsoft/microsoft-ui-xaml/issues/6619)|`CollectionViewSource` not working with C# public fields and C++WinRT| UWP & WASDK 1.5 | C++ :white_check_mark: C# :x:
|[Same Property name with different type conflict](https://github.com/microsoft/microsoft-ui-xaml/issues/9419)|Two `runtimeclass` with properties that has the same name but different type will fail to build (this issue only relates to C++) | UWP & WASDK 1.5.2 | UWP :x: WinUI3 :white_check_mark:
|[DependencyPropertyType](https://github.com/microsoft/microsoft-ui-xaml/issues/9313)|Registering attached DependencyProperty of type DependencyProperty throws exception|WASDK 1.5.2|:x:
|[Exception launching app settings with uri](https://github.com/microsoft/WindowsAppSDK/issues/4460)|Exception when launching appsfeatures-app settings uri with LaunchUriAsync|WASDK 1.5.2|:x:
|[CrossFadeEffect output opposite as documentation](https://github.com/microsoft/Win2D/issues/956)|Win2d `CrossFadeEffect` output opposite effect as documented|Win2D.WinUI 1.2.0|:x:
|[BitmapIcon not respond to ShowAsMonochrome change](https://github.com/microsoft/microsoft-ui-xaml/issues/9792)|BitmapIcon does not respond to ShowAsMonochrome change, and is documented nowhere.|1.6.240701003-exp2|:x:
|[C++WinRT does not correctly handles Chinese characters using Windows.Foundation.Uri](https://github.com/microsoft/cppwinrt/issues/1424)|Parsing the query string from a uri with Chinese character gives empty result|cppwinrt 2.0.240405.15| :x: