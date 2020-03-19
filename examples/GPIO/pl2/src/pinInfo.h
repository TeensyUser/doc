#include "core_pins.h"

struct info_t
{
    unsigned pin;
    unsigned port;
    unsigned bit;
};

class Pin
{
 public:
    inline Pin(unsigned pin, unsigned Mode = INPUT);
    unsigned getPinNr() const { return pinNr; }
    unsigned getBitNr() const { return bitNr; }
    unsigned getPortNr()const { return portNr; }    

 protected:
    const unsigned pinNr;
    const uintptr_t pinCfg;
    const unsigned portNr;
    const unsigned bitNr;    
};

Pin::Pin(unsigned pin, unsigned mode)
    : pinNr(pin),
      pinCfg((uintptr_t)digital_pin_to_info_PGM[pin].config), // address of pin config register
      portNr((pinCfg - (uintptr_t) & PORTA_PCR0) / 0x1000),   // cfg base addresses are 4kB aligned staring with PORTA_PCR0  
      bitNr((pinCfg & 0xFFF) / 4)                             // each bit has to 4 consecutive 32bit cfg registers 
{
    pinMode(pinNr, mode);
}

