#pragma once
#include "Arduino.h"
#include <Joystick.h>

class SWButton{
private:
  int pin;
  char key;
  bool rdt;
  Joystick_ *Joystick;
public:
    SWButton(int pin,char key,Joystick_ *Joystick)
    {
      this->pin=pin;
      this->key=key;
      this->rdt=false;
      this->Joystick=Joystick;
    }
    void checkButton()
    {
      byte buttonState = digitalRead(pin);
      if (buttonState == LOW) {
      //Keyboard.press(key);
      Joystick->pressButton(pin);
      rdt=true;
      }
      else
      {
        if(rdt)
        {
          rdt=false;
          //Keyboard.release(key);
          Joystick->releaseButton(pin);
        }
      }
    }
};
