#pragma once
#include "Arduino.h"

class PotenciometerControll{
    private:
    int pin;
    protected:
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
        if(data>lastData-40 && data<lastData+40)
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
