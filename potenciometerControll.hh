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
        Serial.println(lastData);
        Serial.println(data);
        if(data>lastData-20 && data<lastData+20)
        {
          return;
        }
        else
        {
          Serial.println("here");
          processData(data);
          this->lastData=data;
        }
    } 
    virtual void processData(int data)
    {
      return;
    }
  };
