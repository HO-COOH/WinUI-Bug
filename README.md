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
|~~[C++WinRT does not correctly handles Chinese characters using Windows.Foundation.Uri](https://github.com/microsoft/cppwinrt/issues/1424) [Microsoft QA Link](https://learn.microsoft.com/en-us/answers/questions/1804759/c-winrt-does-not-correctly-handles-chinese-charact)~~|~~Parsing the query string from a uri with Chinese character gives empty result~~|~~cppwinrt 2.0.240405.15~~| My fault, read [uri doc](https://learn.microsoft.com/en-us/uwp/api/windows.foundation.uri?view=winrt-26100#remarks）
|[Svg image not rendering in remote desktop with a higher dpi](https://github.com/microsoft/microsoft-ui-xaml/issues/9799)|Svg image disappear when first launched on a PC, then connect to it with another PC that has higher DPI using remote desktop|WASDK 1.5.2|:x:
|[HTML select popup not following webview2](https://github.com/microsoft/microsoft-ui-xaml/issues/9569)|select popup in a web page is not following webview2 control itself when scrolled.|Windows App SDK 1.5.2: 1.5.240404000|:x: They closed as internally tracked. So I have to track it myself.
|[FindName not working in WinUI3](https://github.com/microsoft/microsoft-ui-xaml/issues/9842)|`FindName()` fails to load a `x:Load="False"` element in winui3, while UWP does|WASDK 1.5.2|:x:
|[Crash in Microsoft.VisualStudio.DesignTools.WinUITap.dll](https://github.com/microsoft/microsoft-ui-xaml/issues/9884)|WinUI3 app crash in visual studio debugging|WASDK 1.5.2|:x:
|[ThemeResource failed to assign to custom property](https://github.com/microsoft/microsoft-ui-xaml/issues/9895)|WinUI3 & UWP app crash in assigning custom property with `ThemeResource`|WASDK 1.6 preview| UWP :x:  WinUI3 :x:
|[RadioButtons SelectionChanged trigger twice](https://github.com/microsoft/microsoft-ui-xaml/issues/9917)|RadioButtons `SelectionChanged` event trigger twice when selecting another item|Winui2 2.8.6 & WinUI3 1.5.2| UWP-WinUI2 :x: WinUI3 :x:
|[Registry of HKEY_CLASS_ROOT when registering a custom scheme with uap:Protocol is not cleaned up after uninstall](https://github.com/microsoft/WindowsAppSDK/issues/4739)| \ | WASDK 1.6 | :x:
|[Inheriting from ListView(Base) breaks SelectedIndex selection](https://github.com/microsoft/microsoft-ui-xaml/issues/8257)| `Selector.SelectedIndex` will be changed seemingly by itself if inherit from `ListViewBase` to create a new control | WASDK 1.6 | :x: