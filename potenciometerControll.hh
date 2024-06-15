#pragma once
#include "Arduino.h"
#include <Timer.h>



class PotenciometerControll {
private:
    int pin;
    Timer t;
    
protected:
    bool rdt;
    int lastData;


public:
    PotenciometerControll(int pin);
    void updateData();
    virtual void processData(int data);
    virtual void reset();
};
