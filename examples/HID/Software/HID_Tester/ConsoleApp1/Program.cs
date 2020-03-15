using HidLibrary;
using System;
using System.Linq;

namespace hid2
{    class Program
    {
        static void Main(string[] args)
        {
            var teensy = HidDevices.Enumerate(0x16C0, 0x0486).Where(d => d.Capabilities.Usage == 512).FirstOrDefault();

            while (teensy != null)
            {
                var report = teensy.ReadReport();
                Console.WriteLine(report.Data[0]);
            }
        }
    }
}