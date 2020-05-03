#define seg1 2
#define seg2 3

unsigned long previousMillis = 0;
const long interval = 1000;
byte num = 0; 
byte numOut1;
byte numOut2;
int pinOut[4] = {11, 10, 9, 8};
byte BCD[11][4] = {
    {0,0,0,0},
    {0,0,0,1},
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1},
    {1,1,1,1}
};

void setup() {
    Serial.begin(9600);

    pinMode(seg1, OUTPUT);
    pinMode(seg2, OUTPUT);
    for (int i = 0; i < 4; i++) {
        pinMode(pinOut[i], OUTPUT);
    }

    digitalWrite(seg1, HIGH);
    digitalWrite(seg2, HIGH);
    for (int i = 0; i < 4; i++) {
        digitalWrite(pinOut[i], BCD[0][i]);
    }
    digitalWrite(seg1, LOW);
    digitalWrite(seg2, LOW);
}

void loop() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        num++;
        previousMillis = currentMillis;
        if (num > 59) {
            num = 0;
        }
        
        numOut1 = decToBcd(num % 10);
        digitalWrite(seg1, HIGH);
        for (int i = 0; i < 4; i++) {
            digitalWrite(pinOut[i], BCD[numOut1][i]);
        }
        digitalWrite(seg1, LOW);

        numOut2 = decToBcd(num) >> 4;
        digitalWrite(seg2, HIGH);
        for (int i = 0; i < 4; i++) {
            digitalWrite(pinOut[i], BCD[numOut2][i]);
        }
        digitalWrite(seg2, LOW);
        delay(250);        
    }
}

/*
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}
*/
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
