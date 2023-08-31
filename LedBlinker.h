#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include "led.h"

class LedBlinker{
  private:
    Led led;
    unsigned long lastTimeBlinked;
    unsigned long blinkDelay;
    void toggleLed();
    void toggleLed(byte brightnessValue);

  public:
    LedBlinker() {};
    LedBlinker(Led &led);
    LedBlinker(Led &led, unsigned long blinkDelay);
    void initLed();
    void initLed(byte defaultState);
    void update();
    void update(byte brightnessValue);
    unsigned long getBlinkDelay();
    void setBlinkDelay(unsigned long blinkDelay);
};

#endif