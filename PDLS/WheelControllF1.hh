#pragma once
#include "PotenciometerControll.hh"
#include <Keyboard.h>

class WheelControllF1 : public PotenciometerControll {
private:
    char category;

public:
    WheelControllF1(int pin);
    void reset() override;
    void processData(int data) override;
};
