#include "Arduino.h"
#include <algorithm>
#include "pin.h"

void setup()
{
    while (!Serial && millis() < 1000){}

    Pin *pins1[CORE_NUM_DIGITAL];
    Pin *pins2[CORE_NUM_DIGITAL];

    for (unsigned pinNr = 0; pinNr < CORE_NUM_DIGITAL; pinNr++)
    {
        Pin *p = new Pin(pinNr);
        pins1[pinNr] = p;
        pins2[pinNr] = p;
    }

    std::sort(pins1, pins1 + CORE_NUM_DIGITAL, [](Pin *a, Pin *b) { return a->getPinNr() < b->getPinNr(); }); // Sort pins1 by pin
    std::sort(pins2, pins2 + CORE_NUM_DIGITAL, [](Pin *a, Pin *b)                                             // Sort pins2 by GPIO and Bit
    {
        if (a->getGpioNr() < b->getGpioNr()) return true;
        if (a->getGpioNr() > b->getGpioNr()) return false;
        if (a->getBitNr() < b->getBitNr())   return true;
        return false;
    });

    // Print results in two columns--------------------------

    Serial.println("PIN   GPIOn-BITm  |  GPIOn-BITm    PIN");
    Serial.println("------------------|-------------------");
    for (unsigned i = 0; i < CORE_NUM_DIGITAL; i++)
    {
        unsigned pin1 = pins1[i]->getPinNr();
        unsigned pin2 = pins2[i]->getPinNr();
        unsigned gpio1 = pins1[i]->getGpioNr();
        unsigned gpio2 = pins2[i]->getGpioNr();
        unsigned bit1 = pins1[i]->getBitNr();
        unsigned bit2 = pins2[i]->getBitNr();
        Serial.printf("%02d  -> GPIO%u-%02u   |   GIPO%u-%02u  ->  %02d\n", pin1, gpio1, bit1, gpio2, bit2, pin2);
    }    
}

void loop()
{   
}

