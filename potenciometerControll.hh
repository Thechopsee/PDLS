#pragma once
#include "Arduino.h"

class PotenciometerControll{
    private:
    int pin;
    int lastData;
    public:
    PotenciometerControll(int pin)
    {
      this->pin=pin;
      this->lastData=0;
      pinMode(pin,INPUT);
    }
    void updateData()
    {
        int data=analogRead(pin);
        if(data>lastData-20 && data<lastData+20)
        {
          return;
        }
        else
        {
          processData(data);
          this->lastData=data;
        }
    } 
    virtual void processData(int data)
    {
      return;
    }
  };
