
#include <util/atomic.h> // For the ATOMIC_BLOCK macro

//Encoder pins
//arduino 1  
#define Interrupt_1 19
#define Interrupt_2 10

#define Interrupt_3 18
#define Interrupt_4 11

// arduino 2
#define Interrupt_5 2
#define Interrupt_6 12

#define Interrupt_7 3
#define Interrupt_8 13


volatile double temp_1, counter_1 = 0;
volatile double temp_2, counter_2 = 0;
volatile double temp_3, counter_3 = 0;
volatile double temp_4, counter_4 = 0;

void setup() {
  
  // Encoder code
  Serial.begin(9600);

  Encoder_INIT();

}

void loop() {
  // put your main code here, to run repeatedly:
  CHECK_ENCODER(temp_1, counter_1);
  CHECK_ENCODER(temp_2, counter_2);
  CHECK_ENCODER(temp_3, counter_3);
  CHECK_ENCODER(temp_4, counter_4);

  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    temp_1 = counter_1;
  }
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    temp_2 = counter_2;
  }
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    temp_3 = counter_3;
  }
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    temp_4 = counter_4;
  }

  Serial.println(temp_1);
  Serial.println(temp_2);
  Serial.println(temp_3);
  Serial.println(temp_4);
  delay(100); // Add a small delay to make the output readable


}


  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  //counter_1+=digitalRead(Interrupt_2)?-1:1;
  if(digitalRead(Interrupt_2)==LOW) {
  counter_1--;
  }else{
  counter_1++;
  }
  
  }
  
  void ai3() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(Interrupt_4)==LOW) {
  counter_2--;
  }else{
  counter_2++;
  }
  }

  
  void ai5() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(Interrupt_6)==LOW) {
  counter_3--;
  }else{
  counter_3++;
  }
  }

  
  void ai7() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(Interrupt_8)==LOW) {
  counter_4--;
  }else{
  counter_4++;
  }
  }

  void CHECK_ENCODER( volatile double temp  ,  volatile double counter)
  {
    if( counter != temp )
      {
        // Serial.println (counter);
        temp = counter;
      }
  } 

void Encoder_INIT(){
  pinMode(Interrupt_1, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(Interrupt_2, INPUT_PULLUP); // internalเป็น pullup input pin 3
  
  pinMode(Interrupt_3, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(Interrupt_4, INPUT_PULLUP); // internalเป็น pullup input pin 3
  
  pinMode(Interrupt_5, INPUT_PULLUP); // internal pullup input pin 4 
  pinMode(Interrupt_6, INPUT_PULLUP); // internalเป็น pullup input pin 7
  
  pinMode(Interrupt_7, INPUT_PULLUP); // internal pullup input pin 4 
  pinMode(Interrupt_8, INPUT_PULLUP); // internalเป็น pullup input pin 7
  
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
 // attachInterrupt(0, ai0, RISING);   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(Interrupt_1), ai1, RISING);   
   //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
 // attachInterrupt(0, ai2, RISING);   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(Interrupt_3), ai3, RISING);   
   //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
 // attachInterrupt(0, ai4, RISING);   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(Interrupt_5), ai5, RISING);   
   //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
 // attachInterrupt(0, ai6, RISING);   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(Interrupt_7), ai7, RISING);   

  
}


