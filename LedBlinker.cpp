#include "LedBlinker.h"

LedBlinker::LedBlinker(Led &led){
  this->led = led;
  lastTimeBlinked = millis();
  this->blinkDelay = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long blinkDelay){
  this->led = led;
  lastTimeBlinked = millis();
  this->blinkDelay = blinkDelay;
}

void LedBlinker::initLed(){
  led.init();
}

void LedBlinker::initLed(byte defaultState){
  led.init(defaultState);
}

void LedBlinker::toggleLed(){
  led.toggle();
}

void LedBlinker::toggleLed(byte brightnessValue){
  led.toggle(brightnessValue);
}

void LedBlinker::update(){
  unsigned long timeNow = millis();
  if(timeNow - lastTimeBlinked >= blinkDelay){
    lastTimeBlinked = timeNow;
    toggleLed();
  }
}

void LedBlinker::update(byte brightnessValue){
  unsigned long timeNow = millis();
  if(timeNow - lastTimeBlinked >= blinkDelay){
    lastTimeBlinked = timeNow;
    toggleLed(brightnessValue);
  }
}

unsigned long LedBlinker::getBlinkDelay(){
  return blinkDelay;
}

void LedBlinker::setBlinkDelay(unsigned long blinkDelay){
  this->blinkDelay = blinkDelay;
}