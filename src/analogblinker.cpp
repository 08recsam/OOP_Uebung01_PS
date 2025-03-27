#include "analogblinker.h"

// ****************************************************************************
// ************************** analogblinker ************************************
// ****************************************************************************
void analogblinker::setblinktime(uint16_t bt)
{
    if (bt <= 1000 && bt >= 10)
    {
        blinkTime = bt;
    }
    else
        Serial.println("...falscher wert du skibidi");
}
void analogblinker::init(uint8_t _pin5, uint8_t _pin6, uint16_t _blinkTime, uint8_t _polltime, bool _sync, bool _enable)
{
    pin5 = _pin5;
    pin6 = _pin6;
    blinkTime = _blinkTime;
    polltime = _polltime;
    sync = _sync;
    enable = _enable;
}

void analogblinker::poll()
{
    if (!enable)
    {
        analogWrite(pin5, 0);
        analogWrite(pin5, 0);
        return;
    }
    else if (millis() - lastpoll > polltime)
    {
        step = 256 / (blinkTime / polltime);
        dutycycle += step;
        if (dutycycle >= 511)
        {
            dutycycle = 0;
        }
        uint16_t pwm = dutycycle > 255 ? 511 - dutycycle : dutycycle;
        analogWrite(pin5, pwm);
        if (sync)
            analogWrite(pin5, pwm);
        else
            analogWrite(pin6, 255 - pwm);
        lastpoll = millis();
    }
}