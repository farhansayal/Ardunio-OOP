#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
  private:
    byte pin;
    byte state;
  public:
    Led() {}
    Led(byte pin);
    void init();
    void init(byte defaultState);
    void on();
    void on(byte brightnessValue);
    void off();
    void off(byte brightnessValue);
    bool isPowerOn();
    void toggle();
    void toggle(byte brightnessValue);
};

#endif