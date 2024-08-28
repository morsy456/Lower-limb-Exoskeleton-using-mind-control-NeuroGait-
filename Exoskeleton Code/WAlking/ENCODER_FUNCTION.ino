#include "INTERFACE.h"

/*
void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(Interrupt_1)==LOW) {
  counter_1++;
  }else{
  counter_1--;
  }
  }
  */

  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  //counter_1+=digitalRead(Interrupt_2)?-1:1;
  if(digitalRead(Interrupt_2)) {
  counter_1--;
  }else{
  counter_1++;
  }
  
  }
/*
  void ai2() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(Interrupt_3)==LOW) {
  counter_2++;
  }else{
  counter_2--;
  }
  }
  */

  void ai3() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(Interrupt_4)==LOW) {
  counter_2--;
  }else{
  counter_2++;
  }
  }
/*
  void ai4() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(Interrupt_5)==LOW) {
  counter_3++;
  }else{
  counter_3--;
  }
  }
 */ 

  void ai5() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(Interrupt_6)) {
  counter_3--;
  }else{
  counter_3++;
  }
  }
/*
  void ai6() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(Interrupt_7)==LOW) {
  counter_4++;
  }else{
  counter_4--;
  }
  }
*/  
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



