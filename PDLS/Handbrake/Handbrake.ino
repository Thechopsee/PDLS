#pragma once
#include <Joystick.h>

const int ELEMENT_COUNT_MAX = 0; //max number of digital pins used on board
const int CONTROLL_COUNT_MAX = 3;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
ELEMENT_COUNT_MAX, 0, // Button Count, Hat Switch Count
false, false, false, // X and Y, but no Z Axis
false, false, false, // No Rx, Ry, or Rz
false, false, // No rudder or throttle
false, true, false); // No accelerator, brake, or steering;

void setup() {
  Joystick.begin();
  Serial.begin(9600);
   
  pinMode(A0,INPUT);

  Joystick.setBrakeRange(0, 200);
}

void loop() {
  int brake=(analogRead(A0)-1023)*-1;
  Serial.println(brake);
  Joystick.setBrake(brake);
  
  delay(50);
}
