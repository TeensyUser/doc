uint8_t report[64];
void setup()
{
}

void loop()
{
    report[0] = millis()/100;
    usb_rawhid_send(report, 1000);
    delay(100);
}