#include "MFDMenuControll.hh"

MFDMenuControll::MFDMenuControll(int pin, bool direct) : PotenciometerControll(pin) {
    this->direction = direct;
}

void MFDMenuControll::reset() {
    if (direction) {
        Keyboard.release('l');
        Keyboard.release('r');
    } else {
        Keyboard.release('u');
        Keyboard.release('d');
    }
}

void MFDMenuControll::processData(int data) {
    int comp = 0;
    if (data > lastData + 20) {
        comp = 1;
    } else if (data < lastData - 20) {
        comp = 2;
    }

    if (direction) {
        if (comp == 2) {
            Keyboard.press('l');
        } else if (comp == 1) {
            Keyboard.press('r');
        }
    } else {
        if (comp == 2) {
            Keyboard.press('d');
        } else if (comp == 1) {
            Keyboard.press('u');
        }
    }
    rdt=false;
}
