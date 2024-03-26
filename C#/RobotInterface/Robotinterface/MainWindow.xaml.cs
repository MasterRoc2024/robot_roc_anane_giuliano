using System.IO.Ports;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using ExtendedSerialPort_NS;
using static System.Net.Mime.MediaTypeNames;
using static Robotinterface.Class1;

namespace Robotinterface
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private ExtendedSerialPort serialPort1;
        DispatcherTimer timerAffichage;
        Robot robot = new Robot();
        byte[] byteList = new byte[20];
        public MainWindow()
        {
            InitializeComponent();
            serialPort1 = new ExtendedSerialPort("COM8", 115200, Parity.None, 8, StopBits.One);
            serialPort1.Open();
            serialPort1.DataReceived += SerialPort1_DataReceived;

            timerAffichage = new DispatcherTimer();
            timerAffichage.Interval = new TimeSpan(0, 0, 0, 0, 100);
            timerAffichage.Tick += TimerAffichage_Tick; ;
            timerAffichage.Start();

        }
        //Time span = time interval that is the difference between 2 times measured, used to compare two C# DATETIME object to find the difference between the dates
        private void TimerAffichage_Tick(object? sender, EventArgs e)
        {
            while (robot.byteListReceived.Count>0)
            {
                var c = robot.byteListReceived.Dequeue();
                textBoxReception.Text += "0x"+c.ToString("X2")+" ";
            }
        }

        string receivedText = "";

        private void SerialPort1_DataReceived(object? sender, DataReceivedArgs e)
        {
            ////robot.receivedText += Encoding.UTF8.GetString(e.Data, 0, e.Data.Length);
            foreach (var item in e.Data)
            {
                robot.byteListReceived.Enqueue(item);
            }
        }

        bool toggle = true;
        private void ButtonEnvoyer_Click_1(object sender, RoutedEventArgs e)
        {
            SendMessage();

        }

        private void SendMessage()
        {
            textBoxReception.Text += "recu: " + textBoxEmission.Text + "\n";
            textBoxEmission.Text = "";
            ///serialPort1.WriteLine("test");
        }
        private void ClearMessage()
        {
            textBoxReception.Clear();
        }
        private void textBoxEmission_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();
            }
        }

        private void textBoxEmission_TextChanged(object sender, TextChangedEventArgs e)
        {

        }


        private void ButtonClear_Click_1(object sender, RoutedEventArgs e)
        {
            ClearMessage();
        }

        private void ButtonTest_Click_1(object sender, RoutedEventArgs e)
        {
            
            for (int i = 0; i < byteList.Length; i++)
            {
                byteList[i] = (byte)(2 * i);
            }

            serialPort1.Write(byteList, 0, byteList.Length);
        }
    }
}