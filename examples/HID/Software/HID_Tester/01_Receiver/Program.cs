using HidLibrary;
using System;
using System.Linq;

namespace receiver
{
    class Program
    {
        static void Main(string[] args)
        {
            var teensy = HidDevices.Enumerate(0x16C0, 0x0486)    // 0x486 = Raw HID 
                        .Where(d => d.Capabilities.Usage == 512) // usage 512 -> RawHID, the other one is SerEMU
                        .FirstOrDefault();                       // take the first one we find on the USB bus

            while (teensy != null)
            {
                var report = teensy.ReadReport();                // request a report from the teensy  
                Console.WriteLine(report.Data[0]);               // and write the first byte on the console
            }
        }
    }
}