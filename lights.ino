int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int pin7 = 8;
int pin8 = 9;
int pin9 = 10;
int pin10 = 11;
int pin11 = 12;
int pin12 = 13;
int pin13 = A0;
int pin14 = A1;
int pin15 = A2;
int pin16 = A3;

int allPins = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16};

int pinCount = 16

void setup(){

for(int i=0;i<pinCount;i++){
    pinMode(allPins[i], OUTPUT);
}

void loop(){



}
