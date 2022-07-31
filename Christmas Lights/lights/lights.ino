int d1 = 100;    // .1 second delay
int d2 = 250;    // .25 second delay
int d3 = 500;    // .5 second delay
int d4 = 1000;   // 1 second delay

// array holding all delay values
int delays[] = {d1, d2, d3, d4};

// initialize all pin variables
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

// define all pin arrays here 

// array containing all pins and pin count
int allPins[] = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16};
int allPinCount = 16;

// array holding all even numbered pins and pin count
int evenPins[] = {pin2, pin4, pin6, pin8, pin10, pin12, pin14, pin16};
int enenPinCount = 8;

// array golding all odd pins and pin count
int oddPins[] = {pin1, pin3, pin5, pin7, pin9, pin11, pin13, pin15};
int oddPinCount = 8;

// function definitions below this line, these are the lighting patterns

void chaseLowHigh(){
    int count = 0;
    while (count < 10){
        for(int i=0; i<allPinCount; i++){
            digitalWrite(allPins[i], HIGH);
            delay(d1);
            digitalWrite(allPins[i], LOW);
            delay(d1);
            count++;
            }
    }
}

void alternateEvenOdd(){
  int loopCount = 0;
  while(loopCount < 5){
    for(int i=0; i<8; i++){
      digitalWrite(evenPins[i], HIGH);
    }
    delay(d4);
    for(int i=0; i<8; i++){
      digitalWrite(evenPins[i], LOW);
   }
    for(int i=0; i<8; i++){
      digitalWrite(oddPins[i], HIGH);
   }
   delay(d4);
   for(int i=0; i<8; i++){
      digitalWrite(oddPins[i], LOW);
   }
   loopCount++;
 }
}

// Function array for pulling a random member and executing
void (*pattern[])(void) = {
  chaseLowHigh,
  alternateEvenOdd
};

void setup(){
    for(int i=0; i<allPinCount; i++){
        pinMode(allPins[i], OUTPUT);
     };
}

void loop(){
// call random function from the array
    int i = random(3); // update to number of functions+1
    (*pattern[i])();
}
