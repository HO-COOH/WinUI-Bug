#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.UI.h>

namespace winrt::CrossFadeEffectBug_WinUI3::implementation
{
	void MainWindow::Border_SizeChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::SizeChangedEventArgs const& e)
	{
		winrt::Microsoft::Graphics::Canvas::Effects::ColorSourceEffect color1;
		color1.Color(winrt::Windows::UI::Colors::Red());

		winrt::Microsoft::Graphics::Canvas::Effects::ColorSourceEffect color2;
		color2.Color(winrt::Windows::UI::Colors::Green());

		winrt::Microsoft::Graphics::Canvas::Effects::CrossFadeEffect crossFadeEffect;
		crossFadeEffect.Source1(color1);
		crossFadeEffect.Source2(color2);
		
		//doc: https://microsoft.github.io/Win2D/WinUI2/html/P_Microsoft_Graphics_Canvas_Effects_CrossFadeEffect_CrossFade.htm
		//according to doc, this should output Source1, aka red
		crossFadeEffect.CrossFade(0.0f);

		//this should output Source2, aka green
		//crossFadeEffect.CrossFade(1.0f);
	
		auto host = sender.as<winrt::Microsoft::UI::Xaml::UIElement>();
		auto compositor = winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::GetElementVisual(host).Compositor();
		auto visual = compositor.CreateSpriteVisual();
		visual.Size(host.ActualSize());
		visual.Brush(compositor.CreateEffectFactory(crossFadeEffect).CreateBrush());
		winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(host, visual);
	}

}
