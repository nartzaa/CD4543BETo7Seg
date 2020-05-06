#ifndef CD4543BETo7Seg_H
#define CD4543BETo7Seg_H

#include "Arduino.h"

class CD4543BETo7Seg {
    private:
        int _dOut[4];
        int pinE;
        int _pinE0, _pinE1;
        byte _val;
    public:
        int dOut[4];

        CD4543BETo7Seg();
        CD4543BETo7Seg(int pinA, int pinB, int pinC, int pinD);

        void dataPin(int pinA, int pinB, int pinC, int pinD);
        void enablePin(int pinE0, int pinE1);
        void write(int val);
        void digit(byte val, int pinE);
        byte decToBcd(byte val);
        byte bcdToDec(byte val);
};
#endif  // #ifndef CD4543BETo7Seg_H