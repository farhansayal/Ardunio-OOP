#include "led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "TrafficLight.h"

#define redPin 3
#define yellowPin 5
#define greenPin 6
#define buttonPin 2
#define analogPin A0

Led redLed(redPin);
Led yellowLed(yellowPin);
Led greenLed(greenPin);

LedBlinker greenLedBlinker(greenLed, 250);

PushButton pushButton(buttonPin, true, true);

Potentiometer potentiometer(analogPin);

TrafficLight trafficLight(redLed, yellowLed, greenLed, greenLedBlinker, pushButton, potentiometer);

void setup() {
  // put your setup code here, to run once:
  trafficLight.init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  trafficLight.update();
    
}
