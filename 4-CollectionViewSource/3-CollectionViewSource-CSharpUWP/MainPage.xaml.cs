using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace _3_CollectionViewSource_CSharpUWP
{
    public class GroupedData
    {
        public string Title = "Title";
        public ObservableCollection<string> data;
    }

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public ObservableCollection<GroupedData> groups;
        public MainPage()
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
}
