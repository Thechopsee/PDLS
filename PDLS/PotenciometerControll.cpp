#include "PotenciometerControll.hh"

PotenciometerControll::PotenciometerControll(int pin) {
    this->pin = pin;
    this->lastData = 0;
    this->rdt = true;
    pinMode(pin, INPUT);
}

void PotenciometerControll::updateData() {
    int data = analogRead(pin);
    if (data > lastData - 40 && data < lastData + 40) {
        return;
    } else {
        processData(data);
        this->lastData = data;
    }
    if (rdt == false) {
        rdt = true;
        reset();
    }
}

void PotenciometerControll::processData(int data) {
}

void PotenciometerControll::reset() {
}