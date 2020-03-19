#include "Arduino.h"
#include "pinInfo.h"

#if defined(KINETISK) || defined(KINETISL)

bool getInfo(info_t* info, unsigned pin)
{
    if(pin >= CORE_NUM_DIGITAL) return false;

    constexpr uint32_t PORTA_PCR = (uint32_t)&PORTA_PCR0;
    constexpr uint32_t PORTB_PCR = (uint32_t)&PORTB_PCR0;
    constexpr uint32_t PORTC_PCR = (uint32_t)&PORTC_PCR0;
    constexpr uint32_t PORTD_PCR = (uint32_t)&PORTD_PCR0;
    constexpr uint32_t PORTE_PCR = (uint32_t)&PORTE_PCR0;
    
    uint32_t cfg = (uint32_t)digital_pin_to_info_PGM[pin].config;
    switch (cfg & ~0xFFF)
    {
        case PORTA_PCR:
            info->pin = pin;
            info->bit = (cfg - PORTA_PCR) >> 2;
            info->port = 0;
            break;

        case PORTB_PCR:
            info->pin = pin;
            info->bit = (cfg - PORTB_PCR) >> 2;
            info->port = 1;
            break;

        case PORTC_PCR:
            info->pin = pin;
            info->bit = (cfg - PORTC_PCR) >> 2;
            info->port = 2;
            break;

        case PORTD_PCR:
            info->pin = pin;
            info->bit = (cfg - PORTD_PCR) >> 2;
            info->port = 3;
            break;

        case PORTE_PCR:
            info->pin = pin;
            info->bit = (cfg - PORTE_PCR) >> 2;
            info->port = 4;
            break;

        default:
            info->pin = pin;
            info->bit = -1;
            info->port = -1;
            break;
    }   

    return true;
}

#elif defined (KINETISK)

bool getInfo(info_t* inf, unsigned pin)
{

    constexpr uint32_t PORTA_PCR = (uint32_t)&PORTA_PCR0;
    constexpr uint32_t PORTB_PCR = (uint32_t)&PORTB_PCR0;
    constexpr uint32_t PORTC_PCR = (uint32_t)&PORTC_PCR0;
    constexpr uint32_t PORTD_PCR = (uint32_t)&PORTD_PCR0;

    unsigned bit, port;

    auto cfg = (uint32_t)digital_pin_to_info_PGM[pin].config;

    // if (pin >= CORE_NUM_DIGITAL) return false;

    // inf->pin = pin;

    // digitalPinToPortReg(pin);
}

#elif defined(ARDUINO_TEENSY40)

// a sldfkjasölfj

#endif