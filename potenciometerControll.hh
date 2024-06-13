#pragma once
#include "Arduino.h"

class PotenciometerControll{
    private:
    int pin;
    protected:
    bool rdt;
    int lastData;
    public:
    PotenciometerControll(int pin)
    {
      this->pin=pin;
      this->lastData=0;
      this->rdt=true;
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
        if(rdt==false)
        {
          rdt=true;
          reset();
        }
    } 
    virtual void processData(int data)
    {
      return;
    }
    virtual void reset()
    {
      return;  
    }
  };
