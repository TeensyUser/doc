#pragma once
#include "Arduino.h"

#include <functional>

using callback_t = std::function<void(void)>;

class SimpleTimer
{
 public:
    void begin(unsigned period, callback_t callback);
    void tick(); // call this as often as possible

 protected:
    unsigned period;
    elapsedMicros timer;
    callback_t callback;
};

