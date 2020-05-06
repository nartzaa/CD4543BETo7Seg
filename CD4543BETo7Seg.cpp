#include "CD4543BETo7Seg.h"

CD4543BETo7Seg::CD4543BETo7Seg() {}
CD4543BETo7Seg::CD4543BETo7Seg(int pinA, int pinB, int pinC, int pinD) {
    dataPin(pinA, pinB, pinC, pinD);
}

void CD4543BETo7Seg::dataPin(int pinA, int pinB, int pinC, int pinD) {
    _dOut[0] = pinA;
    _dOut[1] = pinB;
    _dOut[2] = pinC;
    _dOut[3] = pinD;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
}

void CD4543BETo7Seg::enablePin(int pinE0, int pinE1) {
    _pinE0 = pinE0;
    _pinE1 = pinE1;

    pinMode(pinE0, OUTPUT);
    pinMode(pinE1, OUTPUT);

    
    digitalWrite(pinE0, HIGH);
    digitalWrite(pinE1, HIGH);
    digitalWrite(_dOut[0], LOW);
    digitalWrite(_dOut[1], LOW);
    digitalWrite(_dOut[2], LOW);
    digitalWrite(_dOut[3], LOW);
    digitalWrite(pinE0, LOW);
    digitalWrite(pinE1, LOW);
}

void CD4543BETo7Seg::write(int val) {
    _val = decToBcd(val);
    digit(_val, _pinE0);
    digit(_val >> 4, _pinE1);
}

byte CD4543BETo7Seg::bcdToDec(byte BcdN) {
    return((BcdN / 16 * 10) + (BcdN % 16));
}

byte CD4543BETo7Seg::decToBcd(byte DecN) {
    return((DecN / 10 * 16) + (DecN % 10));
}

void CD4543BETo7Seg::digit(byte dval, int pinE) {
    digitalWrite(pinE, HIGH);
    digitalWrite(_dOut[0], (dval & 0x1) != 0);
    digitalWrite(_dOut[1], (dval & 0x2) != 0);
    digitalWrite(_dOut[2], (dval & 0x4) != 0);
    digitalWrite(_dOut[3], (dval & 0x8) != 0);
    digitalWrite(pinE, LOW);
}

