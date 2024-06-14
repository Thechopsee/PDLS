#pragma once
#include <Vector.h>
#include "potenciometerControll.hh"
#include "WheelControllF1.hh"
#include "MFDMenuControll.hh"
#include <Keyboard.h>
#include <Joystick.h>
#include "SWButton.hh"

const int ELEMENT_COUNT_MAX = 14; //max number of digital pins used on board
const int CONTROLL_COUNT_MAX = 3;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
ELEMENT_COUNT_MAX, 0, // Button Count, Hat Switch Count
false, false, false, // X and Y, but no Z Axis
false, false, false, // No Rx, Ry, or Rz
false, false, // No rudder or throttle
true, true, true); // No accelerator, brake, or steering;


Vector<SWButton*> swbuttons;
Vector<PotenciometerControll*> controlls;

void setup() {
  Keyboard.begin();
  Joystick.begin();
  Serial.begin(9600);
  for(int i=1;i<=ELEMENT_COUNT_MAX;i++)
  {
      pinMode(i, INPUT_PULLUP);
  }
  
  SWButton* storage_array[ELEMENT_COUNT_MAX];
  swbuttons.setStorage(storage_array);
  PotenciometerControll* storage_array_controll[CONTROLL_COUNT_MAX];
  controlls.setStorage(storage_array_controll);


  swbuttons.push_back(new SWButton(1,' ',&Joystick));
  swbuttons.push_back(new SWButton(2,' ',&Joystick));
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

  //storage_array_controll.push_back(new WheelControllF1(A1));
   
  pinMode(A0,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

  controlls.push_back(new WheelControllF1(A1));
  controlls.push_back(new MFDMenuControll(A2,true));
  controlls.push_back(new MFDMenuControll(A3,false));
  Joystick.setAcceleratorRange(0, 70);
  Joystick.setBrakeRange(0, 160);
}

void loop() {
  int steValue=analogRead(A0);
  int power=analogRead(A4);
  power=(power-1023)*-1;
  Joystick.setAccelerator(power);
 
  int brake=analogRead(A5);
  brake=(brake-1023)*-1;
  
  Joystick.setBrake(brake);
  Joystick.setSteering(steValue);
  for(int i=0;i<controlls.size();i++)
  {
    controlls[i]->updateData();
  }
  for (int i = 0; i < swbuttons.size(); ++i) 
  {
    swbuttons[i]->checkButton();
  }
  delay(50);
}
