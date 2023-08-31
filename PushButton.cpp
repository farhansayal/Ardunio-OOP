#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(byte pin, bool isPullUp, bool internalPullUpActivated){
  _buttonPin = pin;
  _isPullUp = isPullUp;
  _internalPullUpActivated = internalPullUpActivated;
  _state = digitalRead(_buttonPin);
}

void PushButton::init(){
  if (_isPullUp && _internalPullUpActivated){
    pinMode(_buttonPin, INPUT_PULLUP);
  }
  else
    pinMode(_buttonPin, INPUT);
  
  readState();
  
}

void PushButton::readState(){
  unsigned long int timeNow = millis();
  if (timeNow - _lastTimeStateChanged >= _debounceDelay){
    byte newState = digitalRead(_buttonPin);
    if (newState != _state){
      _state = newState;
      _lastTimeStateChanged = timeNow;
    }
  }
  _state = digitalRead(_buttonPin);
}

bool PushButton::isPressed(){
  readState();
  if(_isPullUp){
    return (_state==LOW);
  }
  else {
    return (_state==HIGH);
  }
}