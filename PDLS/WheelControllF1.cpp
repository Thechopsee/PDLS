#include "WheelControllF1.hh"

WheelControllF1::WheelControllF1(int pin) : PotenciometerControll(pin) {
    category = 'h';
}

void WheelControllF1::reset() {
    Keyboard.release(category);
}

void WheelControllF1::processData(int data) {
    char old = category;
    if (data >= 0 && data <= 204) {
        category = 'h';
    } else if (data >= 205 && data <= 408) {
        category = 'm';
    } else if (data >= 409 && data <= 612) {
        category = 's';
    } else if (data >= 613 && data <= 816) {
        category = 'i';
    } else if (data >= 817 && data <= 1023) {
        category = 'w';
    }

    if (category != old) {
        if (rdt) {
            Serial.println(category);
            Keyboard.press(category);
            rdt = false;
        }
    }
}
