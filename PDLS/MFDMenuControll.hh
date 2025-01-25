#pragma once
#include "PotenciometerControll.hh"
#include <Keyboard.h>

class MFDMenuControll : public PotenciometerControll {
private:
    // 0 is up/down 1 is left/right
    bool direction;

public:
    MFDMenuControll(int pin, bool direct);
    void reset() override;
    void processData(int data) override;
};
