#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Arduino.h>

class PushButton{
  private:
    byte _buttonPin;
    byte _state;
    bool _isPullUp;
    bool _internalPullUpActivated;

    unsigned long int _lastTimeStateChanged = millis();
    unsigned int _debounceDelay = 50;

    void readState();
  public:
    PushButton() {}
    PushButton(byte pin, bool isPullUp, bool internalPullUpActivated);
    void init();
    bool isPressed();
};

#endif