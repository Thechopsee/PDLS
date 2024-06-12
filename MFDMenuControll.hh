#pragma once
#include "potenciometerControll.hh"
#include <Keyboard.h>

class MFDMenuControll : public PotenciometerControll
{
  private:
  // 0 is up/down 1 is left/right
  bool direction;
  public:
  MFDMenuControll(int pin,bool direct) : PotenciometerControll(pin) {this->direction=direct;}
  void processData(int data) override
  {
        int comp=0;
        if (data>lastData+20)
        {
            comp = 1;
        }
        else if(data<lastData-20)
        {
            comp = 2;
        }
        if(direction)
        {
          if(comp==2)
          {
            Keyboard.write('l');
          }
          else if(comp==1)
          {
            Keyboard.write('r');
          }
        }
        else
        {
          if(comp==2)
          {
            Keyboard.write('d');
          }
          else if(comp==1)
          {
            Keyboard.write('u');
          }
        }
        
  }
};
