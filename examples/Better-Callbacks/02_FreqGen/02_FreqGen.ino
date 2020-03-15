#include "FrequencyGenerator.h"

FrequencyGenerator gen1(0);

//----------------------------------------------

void setup()
{
    gen1.setFrequency(1'000);
}

void loop()
{
    gen1.tick(); // update
}

