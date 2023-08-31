#include "Arduino.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight(Led &redLed, Led &yellowLed, Led &greenLed, 
               LedBlinker &greenLedBlinker, PushButton &pushButton, Potentiometer &potentiometer){
                
                this->redLed = redLed;
                this->yellowLed = yellowLed;
                this->greenLed = greenLed;
                this->greenLedBlinker = greenLedBlinker;
                this->pushButton = pushButton;
                this->potentiometer = potentiometer;
            }

void TrafficLight::init(){
  redLed.init();
  yellowLed.init();
  greenLed.init();
  pushButton.init();
  
  state = STATE_RED;
  red();
}

void TrafficLight::update(){
  brightnessValue = updateBrightness();
  switch (state) {
    case STATE_RED:{
      red();
      if (pushButton.isPressed()){
        state = STATE_YELLOW;
        yellowStateStartTime = millis();
      }
      break;
    }
      
    case STATE_YELLOW:{
      yellow();
      if(millis() - yellowStateStartTime >= yellowStateDuration){
        state = STATE_GREEN;
        greenStateStartTime = millis();
      }
      break;
    }
      
    case STATE_GREEN:{
      green();
      if(millis() - greenStateStartTime >= greenStateDuration){
        state = STATE_BLINK_GREEN;
        allLedsOff();
        blinkGreenStateStartTime = millis();
      }
      break;
    }

    case STATE_BLINK_GREEN:{
      greenLedBlinker.update(brightnessValue);
      if(millis() - blinkGreenStateStartTime >= blinkGreenStateDuration){
        state = STATE_RED;
      }
      break;
    }
      
    default:
    {
      state = STATE_RED;
      break;
    }
      
  }
}

void TrafficLight::red(){
  redLed.on(brightnessValue);
  yellowLed.off();
  greenLed.off();
}
void TrafficLight::yellow(){
  redLed.off();
  yellowLed.on(brightnessValue);
  greenLed.off();
}
void TrafficLight::green(){
  redLed.off();
  yellowLed.off();
  greenLed.on(brightnessValue);
}
void TrafficLight::allLedsOff(){
  redLed.off();
  yellowLed.off();
  greenLed.off();
}

int TrafficLight::updateBrightness(){
  return potentiometer.getBrightnessValue();
}