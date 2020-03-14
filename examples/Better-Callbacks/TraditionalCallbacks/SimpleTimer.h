#pragma once
#include "Arduino.h"

using callback_t = void (*)(void);   // c++ way to define a function pointer (since c++11)
//typedef void (*callback_t)(void);  // traditional C typedef way works as well

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