#pragma once
#include "Arduino.h"
class SWButton{
private:
  int pin;
  char key;
  bool rdt;
public:
    SWButton(int pin,char key)
    {
      this->pin=pin;
      this->key=key;
      this->rdt=false;
    }
    void checkButton()
    {
      byte buttonState = digitalRead(pin);
      if (buttonState == LOW) {
      Keyboard.press(key);
      rdt=true;
      }
      else
      {
        if(rdt)
        {
          rdt=false;
          Keyboard.release(key);
        }
      }
    }
};