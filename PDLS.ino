#pragma once
#include <Vector.h>

#include <Keyboard.h>
#include <Joystick.h>
#include "button.hh"

const int ELEMENT_COUNT_MAX = 12; //max number of digital pins used on board

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
ELEMENT_COUNT_MAX, 0, // Button Count, Hat Switch Count
false, false, false, // X and Y, but no Z Axis
false, false, false, // No Rx, Ry, or Rz
false, false, // No rudder or throttle
true, true, true); // No accelerator, brake, or steering;


Vector<SWButton*> swbuttons;

void setup() {
  Keyboard.begin();
  Joystick.begin();
  Serial.begin(9600);

  
//  pinMode(2, INPUT_PULLUP);
//  pinMode(3, INPUT_PULLUP);
//  pinMode(4, INPUT_PULLUP);
//  pinMode(5, INPUT_PULLUP);
//  pinMode(6, INPUT_PULLUP);
//  pinMode(7, INPUT_PULLUP);
//  pinMode(8, INPUT_PULLUP);
//  pinMode(9, INPUT_PULLUP);
//  pinMode(10, INPUT_PULLUP);
//  pinMode(11, INPUT_PULLUP);
//  pinMode(12, INPUT_PULLUP);

  SWButton* storage_array[ELEMENT_COUNT_MAX];
  swbuttons.setStorage(storage_array);
//  //buttons.push_back(new SWButton(1,' '))
//  //buttons.push_back(new SWButton(2,' '))
//  swbuttons.push_back(new SWButton(3,(char)KEY_F5));
//  swbuttons.push_back(new SWButton(4,'d'));
//  swbuttons.push_back(new SWButton(5,KEY_RETURN));
//  //swbuttons.push_back(new SWButton(6,'e'));
//  swbuttons.push_back(new SWButton(7,'w'));
//  swbuttons.push_back(new SWButton(8,'c'));
//  swbuttons.push_back(new SWButton(9,(char)KEY_F6));
//  swbuttons.push_back(new SWButton(10,(char) 0x20));
//  swbuttons.push_back(new SWButton(11,'s'));
//  swbuttons.push_back(new SWButton(12,'a'));

  //buttons.push_back(new SWButton(1,' ',&Joystick))
  //buttons.push_back(new SWButton(2,' ',&Joystick))
  swbuttons.push_back(new SWButton(3,(char)KEY_F5,&Joystick));
  swbuttons.push_back(new SWButton(4,'d',&Joystick));
  swbuttons.push_back(new SWButton(5,KEY_RETURN,&Joystick));
  //swbuttons.push_back(new SWButton(6,'e'));
  swbuttons.push_back(new SWButton(7,'w',&Joystick));
  swbuttons.push_back(new SWButton(8,'c',&Joystick));
  swbuttons.push_back(new SWButton(9,(char)KEY_F6,&Joystick));
  swbuttons.push_back(new SWButton(10,(char) 0x20,&Joystick));
  swbuttons.push_back(new SWButton(11,'s',&Joystick));
  swbuttons.push_back(new SWButton(12,'a',&Joystick));

   
  pinMode(A0,INPUT);
  Joystick.setBrakeRange(0, 250);
}

void loop() {
  int steValue=analogRead(A0);
  
  Serial.println((steValue-395)*-1);
  Joystick.setBrake((steValue-395)*-1);
  
  for (int i = 0; i < swbuttons.size(); ++i) 
  {
        swbuttons[i]->checkButton();
  }
  
  delay(50);
}
