#include "SimpleTimer.h"

SimpleTimer timer;

void onTimer()    // callback Function
{
    Serial.printf("Called at %d ms\n", millis());
}

//----------------------------------------------

void setup()
{
    timer.begin(100'000, onTimer);
}

void loop()
{
    timer.tick(); // update
}

