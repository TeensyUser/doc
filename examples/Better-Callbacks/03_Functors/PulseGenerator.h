#pragma once

#include "Arduino.h"

class PulseGenerator
{
 public:
    PulseGenerator(unsigned _pin, unsigned _pulseLength)
        : pin(_pin), pulseLength(_pulseLength)
    {
        pinMode(pin, OUTPUT);
    }

    void operator()()
    {
        digitalWriteFast(pin, HIGH);
        delayMicroseconds(pulseLength);
        digitalWriteFast(pin, LOW);
    }

 protected:
    unsigned pin, pulseLength;
};