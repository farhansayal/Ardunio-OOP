#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"

class TrafficLight{

  private:
  
  Led redLed;
  Led yellowLed;
  Led greenLed;
  LedBlinker greenLedBlinker;
  PushButton pushButton;
  Potentiometer potentiometer;

  enum trafficLightState {
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
    STATE_BLINK_GREEN,
    STATE_ALL_LEDS_OFF,
  };

  int state;

  unsigned long yellowStateStartTime;
  unsigned long greenStateStartTime;
  unsigned long blinkGreenStateStartTime;

  const int yellowStateDuration = 3000;
  const int greenStateDuration = 2000;
  const int blinkGreenStateDuration = 10000;

  int brightnessValue = 255; 

  public:
  TrafficLight() {}
  TrafficLight(Led &redLed, Led &yellowLed, Led &greenLed, 
               LedBlinker &greenLedBlinker, PushButton &pushButton, Potentiometer &Potentiometer);
  void init();
  void update();

  void red();
  void yellow();
  void green();
  void allLedsOff();
  int updateBrightness();
};

#endif