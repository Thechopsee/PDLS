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
  for(int i=1;i<=ELEMENT_COUNT_MAX;i++)
  {
      pinMode(i, INPUT_PULLUP);
  }
  
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
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Joystick.setAcceleratorRange(0, 70);
  Joystick.setBrakeRange(0, 215);
}

void loop() {
  int steValue=analogRead(A0);
  int controll1=analogRead(A1);
  int controll2=analogRead(A2);
  int controll3=analogRead(A3);
  int power=analogRead(A4);
  power=(power-1023)*-1;
  Joystick.setAccelerator(power);
 
  int brake=analogRead(A5);
  brake=(brake-1023)*-1;
  
  
  Joystick.setBrake(brake);
  Joystick.setSteering(steValue);
  
  for (int i = 0; i < swbuttons.size(); ++i) 
  {
        swbuttons[i]->checkButton();
  }
  
  delay(50);
}
