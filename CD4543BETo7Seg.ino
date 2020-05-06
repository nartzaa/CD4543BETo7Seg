#include "CD4543BETo7Seg.h"
CD4543BETo7Seg dsp;

#define digit1 2
#define digit2 3
#define pinA 8
#define pinB 9
#define pinC 10
#define pinD 11

unsigned long previousMillis = 0;
const long interval = 1000;
int num = 0;

void setup() {
    Serial.begin(9600);
    dsp.dataPin(pinA, pinB, pinC, pinD);
    dsp.enablePin(digit1, digit2);
}

void loop() {    
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        num++;
        previousMillis = currentMillis;
        if (num > 59) {
            num = 0;
        }
        dsp.write(num);
    }
    
    /*
    if (Serial.available()) {
        num = Serial.parseInt(); //read int or parseFloat for ..float...
        Serial.println(num,BIN);
        dsp.write(num);
    }*/
}
