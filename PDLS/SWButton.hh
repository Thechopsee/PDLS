#pragma once
#include "Arduino.h"
#include <Joystick.h>

class SWButton {
private:
    int pin;
    char key;
    bool rdt;
    Joystick_ *Joystick;

public:
    SWButton(int pin, char key, Joystick_ *Joystick);
    void checkButton();
};
