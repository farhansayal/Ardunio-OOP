#include <Arduino.h>
#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin){
  this->pin  = pin;
}

int Potentiometer::getBrightnessValue(){
  return map(analogRead(pin), 0, 1023, 0, 255);
}