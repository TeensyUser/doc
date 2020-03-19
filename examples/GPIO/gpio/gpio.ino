#include "Arduino.h"
void printDigitalVal(int pin, int val); // forward declare for standard c++ build systems

constexpr int inputPin = 0;

void setup()
{
    while (!Serial && millis() < 1000) {}

    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(inputPin, INPUT_PULLUP);
    Serial.println("Using INPUT_PULLUP:");
    printDigitalVal(inputPin, digitalReadFast(inputPin));

    pinMode(inputPin, INPUT_PULLDOWN);
    Serial.println("\nUsing INPUT_PULLDOWN:");
    printDigitalVal(inputPin, digitalReadFast(inputPin));
}

void loop()
{
    digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN)); // toggle pin
    delay(150);
}

// Helpers ----------------------------------------------------------

void printDigitalVal(int pin, int val)
{
    Serial.printf("Pin %d value: %s\n", pin, val == 0 ? "LOW" : "HIGH");
}
