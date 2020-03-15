#include "Arduino.h"

uint8_t buf[64];

void setup()
{
   pinMode(LED_BUILTIN, OUTPUT);
}

byte cnt = 0;

void loop()
{
   buf[0] = cnt++;
   usb_rawhid_send(buf, 1000);

   digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN));
   delay(500);
}