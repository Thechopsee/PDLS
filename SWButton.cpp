#include "SWButton.hh"

SWButton::SWButton(int pin, char key, Joystick_ *Joystick) {
    this->pin = pin;
    this->key = key;
    this->rdt = false;
    this->Joystick = Joystick;
}

void SWButton::checkButton() {
    byte buttonState = digitalRead(pin);
    if (buttonState == LOW) {
        Joystick->pressButton(pin);
        rdt = true;
    } else {
        if (rdt) {
            rdt = false;
            Joystick->releaseButton(pin);
        }
    }
}
