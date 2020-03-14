#include "SimpleTimer.h"

void SimpleTimer::begin(unsigned _period, callback_t _callback)
{
    period = _period;
    callback = _callback;
    timer = 0;
}

void SimpleTimer::tick()
{
    if (timer >= period)
    {
        timer -= period;
        callback();
    }
}