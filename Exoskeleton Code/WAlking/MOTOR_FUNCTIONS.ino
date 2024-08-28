#include "INTERFACE.h"
/*
void MOVE_MOTOR_RIGHT_DIR()
{
  digitalWrite(MOTOR_DIR, RIGHT_DIR);
  analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED); // control the speed
}

void MOVE_MOTOR_LEFT_DIR()
{
  digitalWrite(MOTOR_DIR, LEFT_DIR);
  analogWrite(MOTOR_PWM, MOTOR_PWM_SPEED); // control the speed
}
*/
void STOP_MOTOR(int MOTOR_PWM, int MOTOR_DIR)
{
  digitalWrite(MOTOR_DIR, LOW);
  analogWrite(MOTOR_PWM, STOP_MOTOR_SPEED); // control the speed
}

 void MOTOR_INIT(){
  // code motor
  pinMode(MOTOR_PWM_1, OUTPUT);
  pinMode(MOTOR_DIR_1, OUTPUT);
  pinMode(MOTOR_PWM_2, OUTPUT);
  pinMode(MOTOR_DIR_2, OUTPUT);
  pinMode(MOTOR_PWM_3, OUTPUT);
  pinMode(MOTOR_DIR_3, OUTPUT);
  pinMode(MOTOR_PWM_4, OUTPUT);
  pinMode(MOTOR_DIR_4, OUTPUT);
  
 }