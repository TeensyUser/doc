#pragma once
#include "SimpleTimer.h"

class FrequencyGenerator
{
 public:
    FrequencyGenerator(unsigned pin);
    void setFrequency(float Hz);

    void tick() { timer.tick(); }

 protected:
    SimpleTimer timer;
    unsigned pin;
    void onTimer();
};