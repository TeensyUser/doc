uint8_t buf[64];

void setup()
{
}

void loop()
{
    buf[0] = millis()/100;
    usb_rawhid_send(buf, 1000);
    delay(100);
}