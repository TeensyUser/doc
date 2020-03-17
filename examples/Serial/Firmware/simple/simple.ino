#include "Arduino.h"

void setup()
{
}

void loop()
{
  static unsigned cnt = 0;
  Serial.println(cnt++);
  delay(50);
}