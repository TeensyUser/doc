void setup()
{
}

void loop()
{
    char buf[64];

    if(usb_rawhid_recv(buf, 10) > 0)
    {
      Serial.println(buf);
    }
}
