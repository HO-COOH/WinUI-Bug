using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace _3_CollectionViewSource_CSharp;

public class GroupedData
{
    public string Title = "Title";
    public ObservableCollection<string> data;
}

/// <summary>
/// An empty window that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MainWindow : Window
{
    public ObservableCollection<GroupedData> groups;

    public MainWindow()
    {
        this.InitializeComponent();
        groups = new ObservableCollection<GroupedData>();

        GroupedData data = new GroupedData();
        data.data = new ObservableCollection<string>();
        data.data.Add("obj1");
        data.data.Add("obj2");
        data.data.Add("obj3");

        groups.Add(data);
        groups.Add(new GroupedData());
    }
}
