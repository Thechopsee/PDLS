#pragma once
#include "Arduino.h"

class PotenciometerControll {
private:
    int pin;

protected:
    bool rdt;
    int lastData;

public:
    PotenciometerControll(int pin);
    void updateData();
    virtual void processData(int data);
    virtual void reset();
};
