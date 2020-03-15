#include "FrequencyGenerator.h"

FrequencyGenerator::FrequencyGenerator(unsigned _pin)
{
    pin = _pin;
    pinMode(pin, OUTPUT);
}

void FrequencyGenerator::setFrequency(float frequency)
{
    unsigned period = 0.5f * 1E6f / frequency;
    timer.begin(period, [this] { this->onTimer();}); // attach callback
}

void FrequencyGenerator::onTimer()
{
    digitalWriteFast(pin, !digitalReadFast(pin));
}



