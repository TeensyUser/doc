using HidLibrary;
using System;
using System.Json;
using System.Linq;
using System.Net;

namespace hid
{
    class Program
    {
        static void Main(string[] args)
        {    
            var teensy = HidDevices.Enumerate(0x16C0, 0x0486).Where(d => d.Capabilities.Usage == 512).FirstOrDefault();
            if (teensy == null || !teensy.IsConnected) return;            

            for(int loops = 0; loops< 10; loops++)               // don't read too much data from the web page...
            {
                String slip = new WebClient().DownloadString(@"https://api.adviceslip.com/advice");  // read a slip from adviceslip.com
                String advice = JsonValue.Parse(slip)["slip"]["advice"];                             // extract the advice from the json result

                HidReport report = teensy.CreateReport();        // Generate an empty report
                for(int i = 0; i< advice.Take(63).Count(); i++ ) // and copy the characters into it. 
                {                                                // limit to 63 bytes to ensure the report always has a EOS (\0) at the end
                    report.Data[i] = (byte) advice[i];
                }                
                
                teensy.WriteReport(report);                      // send report to teensy 
                Console.WriteLine(advice);                       // echo on console            
            }
        }
    }
}