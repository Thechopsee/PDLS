#pragma once
#include "potenciometerControll.hh"
#include <Keyboard.h>

class WheelControllF1 : public PotenciometerControll
{
private:
    char category;
public:
    WheelControllF1(int pin) : PotenciometerControll(pin) {category='h';}

    void processData(int data) override
    {
        char old=category;
        if (data >= 0 && data <= 204)
        {
            category = 'h';
        }
        else if (data >= 205 && data <= 408)
        {
            category = 'm';
        }
        else if (data >= 409 && data <= 612)
        {
            category = 's';
        }
        else if (data >= 613 && data <= 816)
        {
            category = 'i';
        }
        else if (data >= 817 && data <= 1023)
        {
            category = 'w';
        }
        if(category !=old)
        {
          Serial.println(category);
          Keyboard.write(category);
        }
    }
};
