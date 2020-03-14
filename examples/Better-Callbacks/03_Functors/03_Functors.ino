#include "PulseGenerator.h"
#include "SimpleTimer.h"

SimpleTimer timer;

void setup()
{
    timer.begin(10'000, PulseGenerator(0,2000)); // use a functor as callback and call it every 10ms
}

void loop()
{
    timer.tick();
}
