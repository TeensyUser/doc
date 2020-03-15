#pragma once
#include "Arduino.h"

#include <functional>

using callback_t = std::function<void(void)>;
//using callback_t = void (*)(void);   // c++ way to define a function pointer (since c++11)


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

