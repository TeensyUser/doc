void setup()
{
}

void loop()
{
    char buf[64];

    usb_rawhid_recv(buf, 1000);
    Serial.println(buf);
}
