#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

class Potentiometer{

  private:
    byte pin;
  public:
    Potentiometer() {}
    Potentiometer(byte pin);
    int getBrightnessValue();

};


#endif