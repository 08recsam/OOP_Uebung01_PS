#ifndef DIGITALBLINKER_H
#define DIGITALBLINKER_H

#include <Arduino.h>

class blinker
{
    private:
    bool enable = false;
    uint8_t pin1 = 0;
    bool neg1 = false;
    uint8_t pin2 = 0;
    bool neg2 = false;
    uint16_t blinkTime = 0;
    unsigned long lastblink = 0;
    bool blinkState = false;

    public:
    // PinNr.1, Negierung1, PinNr.2, Negierung2, Blinkzeit [ms], Startzustand
    void init(uint8_t, bool, uint8_t, bool, uint16_t, bool);

    void poll();

    void on();
    void off();
};

#endif