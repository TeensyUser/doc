#include "Arduino.h"
#include "pins.h"
#include <algorithm>
#include <vector>

using namespace pins;

void display(boards);

struct info_t
{
    unsigned pin;
    char port;
    unsigned bit;
};

void setup()
{
    while (!Serial && millis() < 1000) {}

    Serial.println("-----------------------------------------------------");
    Serial.println("Teensy LC");
    Serial.println("-----------------------------------------------------");
    display(T_LC);

    Serial.println("\n-----------------------------------------------------");
    Serial.println("Teensy 3.0, 3.1, 3.2");
    Serial.println("-----------------------------------------------------");
    display(T3_0_1_2);

    Serial.println("\n-----------------------------------------------------");
    Serial.println("Teensy 3.5, 3.6");
    Serial.println("-----------------------------------------------------");
    display(T3_5_6);

    return;
}

void loop()
{
    digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN)); // toggle pin
    delay(150);
}

// Helpers ----------------------------------------------------------

char PortName(portList port)
{
    if (port == portList::na) return 'X';
    return 'A' + port;
}

void display(boards board)
{
    constexpr unsigned pinCnt = sizeof(pinMap) / sizeof(pinMap[0]);
    std::vector<info_t> infosA, infosB;

    info_t info;
    for (unsigned i = 0; i < pinCnt; i++)
    {
        info.pin = i;
        info.port = PortName(pinMap[i][board].port);
        info.bit = pinMap[i][board].pin;
        if (info.port == 'X') break;

        infosA.push_back(info);
        infosB.push_back(info);
    }
    
    // sort infosA by pin number
    std::sort(infosA.begin(), infosA.end(), [](info_t a, info_t b){return a.pin < b.pin;});

    // sort infosB by port and bit 
    std::sort(infosB.begin(), infosB.end(), [](info_t a, info_t b) {
        if (a.port < b.port) return true;
        if (a.port > b.port) return false;
        if (a.bit < b.bit) return true;
        return false;
    });

    Serial.println("Sorted by pin number:     |   Sorted by Port and Bit");
    for (unsigned i = 0; i < infosA.size(); i++)
    {
        unsigned pinA = infosA[i].pin;
        unsigned bitA = infosA[i].bit;
        char portA = infosA[i].port;

        unsigned pinB = infosB[i].pin;
        unsigned bitB = infosB[i].bit;
        char portB = infosB[i].port;

        Serial.printf("Pin %2d  PORT_%c  Bit: %2d   |   PORT_%c  Bit %2d  Pin: %2d  \n", pinA, portA, bitA, portB, bitB, pinB);
    }
}


