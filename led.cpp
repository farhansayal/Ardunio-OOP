#include "Arduino.h"
#include "led.h"

Led::Led(byte pin){
  this->pin  = pin;
}

void Led::init(){
  pinMode(pin, OUTPUT);
}

void Led::init(byte defaultState){
  init();
  if (defaultState == HIGH){
    on();
  }
  else {
    off();
  }

}

void Led::on(){
  state = HIGH;
  digitalWrite(pin, state);
}

void Led::on(byte brightnessValue){
  state = HIGH;
  analogWrite(pin, brightnessValue);
}

void Led::off(){
  state = LOW;
  digitalWrite(pin, state);
}
bool Led::isPowerOn(){
  return (state == HIGH);
}

void Led::toggle(){
  if (isPowerOn()){
    off();
  }
  else {
    on();
  }
}
void Led::toggle(byte brightnessValue){
  if (isPowerOn()){
    off();
  }
  else {
    on(brightnessValue);
  }
}