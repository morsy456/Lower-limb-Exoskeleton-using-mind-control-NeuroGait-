#include <PID_v1.h>
#include "INTERFACE.h"

volatile double temp, counter = 0;

int val = 180 ;
int encoder_val =0;

float kp = 8;
float ki = 15 ;
float kd = 30;

float Theta, Theta_d;
int dt;
unsigned long t;
unsigned long t_prev = 0;
int val_prev =0;
float e, e_prev = 0, inte, inte_prev = 0;
float Vmax =6;
float Vmin = -6;
float V = 0.1;

void setup() {
  
  // code motor
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_DIR, OUTPUT);
  
  //encoder code
  Serial.begin (9600);
  pinMode(Interrupt_2, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(Interrupt_3, INPUT_PULLUP); // internalเป็น pullup input pin 3
  
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);   // suppose to be 2
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);   // suppose to be 3

}

void loop() {
  //encoder code
 // Send th value of counter
  if( counter != temp )
  {
    // Serial.println (counter);
    temp = counter;
  }

}


