#include "Arduino.h"
//#include "pins.h"
#include "pinInfo.h"
#include <algorithm>
#include <vector>

//void display(boards);

void pri(const Pin& p)
{
    

    Serial.printf("%02d -> %c-%02u\n", p.getPinNr(), p.getPortNr() + 'A', p.getBitNr());
}

void setup()
{
    while (!Serial && millis() < 1000) {}

    for (unsigned i = 0; i < CORE_NUM_DIGITAL; i++)
    {
        pri(Pin(i));
    }

    return;
}

void loop()
{
    digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN)); // toggle pin
    delay(150);
}

// Helpers ----------------------------------------------------------

// char PortName(portList port)
// {
//     if (port == portList::na) return 'X';
//     return 'A' + port;
// }

// void display(boards board)
// {
//     constexpr unsigned pinCnt = sizeof(pinMap) / sizeof(pinMap[0]);
//     std::vector<info_t> infosA, infosB;

//     info_t info;
//     for (unsigned i = 0; i < pinCnt; i++)
//     {
//         info.pin = i;
//         info.port = PortName(pinMap[i][board].port);
//         info.bit = pinMap[i][board].pin;
//         if (info.port == 'X') break;

//         infosA.push_back(info);
//         infosB.push_back(info);
//     }

//     // sort infosA by pin number
//     std::sort(infosA.begin(), infosA.end(), [](info_t a, info_t b) { return a.pin < b.pin; });

//     // sort infosB by port and bit
//     std::sort(infosB.begin(), infosB.end(), [](info_t a, info_t b) {
//         if (a.port < b.port) return true;
//         if (a.port > b.port) return false;
//         if (a.bit < b.bit) return true;
//         return false;
//     });

//     Serial.println("Sorted by pin number:     |   Sorted by Port and Bit");
//     for (unsigned i = 0; i < infosA.size(); i++)
//     {
//         unsigned pinA = infosA[i].pin;
//         unsigned bitA = infosA[i].bit;
//         char portA = infosA[i].port;

//         unsigned pinB = infosB[i].pin;
//         unsigned bitB = infosB[i].bit;
//         char portB = infosB[i].port;

//         Serial.printf("Pin %2d  PORT_%c  Bit: %2d   |   PORT_%c  Bit %2d  Pin: %2d  \n", pinA, portA, bitA, portB, bitB, pinB);
//     }
// }
