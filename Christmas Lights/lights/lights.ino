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

int allPins[] = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15, pin16};
int allPinsReverse[] = {pin16, pin15, pin14, pin13, pin12, pin11, pin10, pin9, pin8, pin7, pin6, pin5, pin4, pin3, pin2, pin1};
int evenPins[] = {pin2, pin4, pin6, pin8, pin10, pin12, pin14, pin16};
int oddPins[] = {pin1, pin3, pin5, pin7, pin9, pin11, pin13, pin15};
int eightInFours[] = {pin1, pin2, pin3, pin4, pin9, pin10, pin11, pin12};
int eightInFours2[] = {pin5, pin6, pin7, pin8, pin13, pin14, pin15, pin16};

// function definitions below this line, these are the lighting patterns

void chaseLowHigh(){
   int count = 0;
   int loopCount = random(1,6);
   while (count < loopCount){
      for(int i=0; i<16; i++){
         digitalWrite(allPins[i], HIGH);
         delay(d1);
         digitalWrite(allPins[i], LOW);
         delay(d1);
         }
         count++;
      }
}

void chaseHighLow(){
   int count = 0;
   int loopCount = random(1,6);
   while (count < loopCount){
      for(int i=0; i<16; i++){
         digitalWrite(allPinsReverse[i], HIGH);
         delay(d1);
         digitalWrite(allPinsReverse[i], LOW);
         delay(d1);
         }
         count++;
       }
}

void alternateEvenOdd(){
   int count = 0;
   int loopCount = random(1,6);
   while(count < loopCount){
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
   count++;
   }
}

void alternateFours(){
   int count = 0;
   int loopCount = random(1,6);
   while(count < loopCount){
      for(int i=0; i<8; i++){
         digitalWrite(eightInFours[i], HIGH);
      }
      delay(d4);
      for(int i=0; i<8; i++){
         digitalWrite(eightInFours[i], LOW);
      }
      for(int i=0; i<8; i++){
         digitalWrite(eightInFours2[i], HIGH);
      }
      delay(d4);
      for(int i=0; i<8; i++){
         digitalWrite(eightInFours2[i], LOW);
      }
   count++;
   }
}

void randomOneByOne(){
   int count = 0;
   int ranDelay = delays[(random(0,4))];
   while(count < 16){
      int trigger = random(0,16);
      if(allPins[trigger] == HIGH){
         delay(ranDelay);
         digitalWrite(allPins[trigger], LOW);
      }
      delay(ranDelay);
      digitalWrite(allPins[trigger], HIGH);
      count++;
   }
   for(int i=0; i<16; i++){
      digitalWrite(allPins[i], LOW);
   }
}

void knightRider(){
      int ranDelay = delays[(random(0,4))];
      int loopCount = random(1,6);
      while(count < loopCount){
         for(int i=0; i<16; i++){
            digitalWrite(allPins[i], HIGH);
            delay(ranDelay);
            digitalWrite(allPins[i], LOW);
            delay(ranDelay);
         }
      }
}

// Function array for pulling a random member and executing
void (*pattern[])(void) = {
  chaseLowHigh,
  alternateEvenOdd,
  chaseHighLow,
  randomOneByOne,
  alternateFours,
  knightRider
};

void setup(){
    for(int i=0; i<16; i++){
        pinMode(allPins[i], OUTPUT); // initialize all pins as output
     };
}

void loop(){
// call random function from the array
    int i = random(6); // update to number of functions+1 0 included 
    (*pattern[i])();
}
