#include <PID_v1.h>
#include "INTERFACE.h"

volatile unsigned int temp, counter = 0;

int voltage=0;
int tem=0;

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
 // Send the value of counter
  if( counter != temp )
  {
    // Serial.println (counter);
    temp = counter;
  }
        for(int i=0 ; i<=60 ; i++ )
  {
    digitalWrite(MOTOR_DIR, RIGHT_DIR);
    analogWrite(MOTOR_PWM,  tem);
// control the speed
  
  voltage=float((tem*12.0)/255.0) ;
      double  angle = counter * 0.6 * GEAR_RATIO ;
    
      Serial.print("          ");
      Serial.print(voltage);
    //Serial.print("          ");
    //Serial.print(counter);
      Serial.print("          ");
      Serial.print(angle);
      Serial.println();

      delay(10);
  }
    tem=tem+27;

/*
    digitalWrite(MOTOR_DIR, RIGHT_DIR);  
    analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
    analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
    analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
    analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
    analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
*/
// void ai1() ;
// void ai0() ;

//float VOLTAGE= VOLTAGE_EQUATION(MOTOR_PWM_SPEED);
//float ANGEL= ANGLE_OF_ROTATION_WITH_VOLT(counter);
//MOVE_MOTOR_RIGHT_DIR();
//Accelerate_D_1();
/*
else 
{
  analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED);
 
  }
*/
//MOVE_MOTOR_LEFT_DIR();
//PID myPID(VOLTAGE, ANGEL, 30, 2, 0, 0, 0);
//delay(10000);
/*if( ANGEL >= 360 )
{
  //analogWrite(MOTOR_PWM, STOP_MOTOR_SPEED);
  STOP_MOTOR();

}
*/

   
  

}

