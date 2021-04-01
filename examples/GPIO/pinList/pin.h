#include "core_pins.h"

class Pin
{
public:
    inline Pin(unsigned pin, unsigned Mode = INPUT);
    unsigned getPinNr() const { return pinNr; }
    unsigned getBitNr() const { return bitNr; }
    unsigned getGpioNr() const { return gpioNr; }

protected:
    const unsigned pinNr;
    const uintptr_t pinCfg;
    const unsigned gpioNr;
    const unsigned bitNr;
};

#if defined(KINETISK) || defined(KINETISL)
Pin::Pin(unsigned pin, unsigned mode)
    : pinNr(pin),
      pinCfg((uintptr_t)digital_pin_to_info_PGM[pin].config), // address of pin config register
      gpioNr((pinCfg - (uintptr_t)&PORTA_PCR0) / 0x1000),     // cfg base addresses are 4kB aligned staring with PORTA_PCR0
      bitNr((pinCfg & 0xFFF) / 4)                             // each bit has to 4 consecutive 32bit cfg registers
{
    pinMode(pinNr, mode);
}

#elif defined(ARDUINO_TEENSY40) || defined (ARDUINO_TEENSY41) || defined (ARDUINO_TEENSY_MICROMOD)

Pin::Pin(unsigned pin, unsigned mode)
    : pinNr(pin),
      pinCfg((uintptr_t)digital_pin_to_info_PGM[pinNr].reg),        // address of pin config register
      gpioNr((pinCfg - (uintptr_t)&IMXRT_GPIO6) / 0x4000 + 6),      // cfg base addresses are 4kB aligned staring with PORTA_PCR0
      bitNr(__builtin_ffs(digital_pin_to_info_PGM[pinNr].mask) - 1) // each bit has to 4 consecutive 32bit cfg registers
{
    pinMode(pinNr, mode);
}

#endif
