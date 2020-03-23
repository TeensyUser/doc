using HidLibrary;
using System;
using System.Linq;
using System.Text;
using System.Threading;

namespace hid
{
    class Program
    {
        static void Main(string[] args)
        {
            var teensy = HidDevices.Enumerate(0x16C0, 0x0486).Where(d => d.Capabilities.Usage == 512).FirstOrDefault();
            if (teensy == null || !teensy.IsConnected) return;

            var report = teensy.CreateReport();

            while (teensy.IsConnected && !Console.KeyAvailable)
            {
                String message = "Hello Teensy " + DateTime.Now.ToString("o"); // generate some message string
                Encoding.ASCII.GetBytes(message).CopyTo(report.Data, 0);        // convert to byte array and copy to report

                teensy.WriteReport(report);                                    // send report to teensy 
                Console.WriteLine(message);                                    // echo on console

                Thread.Sleep(200);
            }
        }
    }
}