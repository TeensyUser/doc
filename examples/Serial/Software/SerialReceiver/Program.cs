using System;
using System.IO.Ports;
using System.Linq;
using TeensySharp;

namespace SerialReceiver
{
    class Program
    {
        static void Main(string[] args)
        {
            var watcher = new TeensyWatcher();
            var teensy = watcher.ConnectedDevices.FirstOrDefault();  // Use the first teensy we find on the Bus                      
            
            SerialPort port = new SerialPort(teensy.Port,115200);           // open a serial port for the teensy            
            port.Open();
            
            while(!Console.KeyAvailable)
            {
                Console.WriteLine(port.ReadLine());
            }

            port.Close();
        }
    }
}
