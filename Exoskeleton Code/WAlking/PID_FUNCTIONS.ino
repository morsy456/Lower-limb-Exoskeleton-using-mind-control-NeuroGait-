#include "INTERFACE.h"
/*

//  setting the set point needed 
 int SET_POINT=180; 

  double VOLTAGE = double((MOTOR_PWM_SPEED*12.0)/255.0) ;
  double ANGEL = double(counter * 0.6 * GEAR_RATIO) ;

// time difference 

long T_Current= micros();
 
float  delta_T= ((float)(T_Current-T_prev))/1.0e6;
T_prev=T_Current;


 Position = ANGEL;
// Read the position
  int pos = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  pos = Position;
  interrupts(); // turn interrupts back on
  
// error   depend on ur connection , so u can change it 
int error=  SET_POINT -Position;

// drivative 
float  derivative= (error-e_prev)/(delta_T);

// integral 
e_integral = e_integral + error * delta_T ;

// control signal 
float CONTROL_SIGANL = float (Kp * error   +  Kd * derivative   + Ki * e_integral) ;

// motor power 
float PWR = fabs(CONTROL_SIGANL);
if (PWR > 255 ){
  PWR =255 ;
}

/FT_DIR ;
}/ motor direction 
int direction = RIGHT_DIR ;
if (CONTROL_SIGANL < 0){
  direction = LE

// send signal to motor 
setMotor(direction,PWR,MOTOR_PWM,MOTOR_DIR);

e_prev = error;

if ( Position == (SET_POINT))
{STOP_MOTOR();} 
else if(Position == (SET_POINT)+1)
{STOP_MOTOR();} 


  Serial.print(190);
  Serial.print("  , ");
  Serial.print(0);
   Serial.print("  , ");

  Serial.print(SET_POINT);
  Serial.print(" ");
  Serial.print(pos);
  Serial.println();

*/


void PID_ANGEL_MOTION(int SET_POINT,volatile double counter,int Position_MOTOR ,long T_prev_MOTOR ,float e_prev_MOTOR ,float e_integral_MOTOR, float Kp , float Ki , float Kd, int MOTOR_PWM , int MOTOR_DIR,int PWM_MAX){

 double VOLTAGE = double((MOTOR_PWM_SPEED*12.0)/255.0) ;
  double ANGEL = double(counter * 1.56 * GEAR_RATIO) ;

  // time difference 
  long T_Current= micros();
  float  delta_T= ((float)(T_Current-T_prev_MOTOR))/1.0e6;
  T_prev_MOTOR=T_Current;

  Position_MOTOR = ANGEL;
// Read the Position_MOTOR
  int pos = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  pos = Position_MOTOR;
  interrupts(); // turn interrupts back on

  // error depend on ur connection , so u can change it 
  int error=  SET_POINT -Position_MOTOR;

  // drivative 
  float  derivative= (error-e_prev_MOTOR)/(delta_T);

  // integral 
  e_integral_MOTOR = e_integral_MOTOR + error * delta_T ;
    
  // control signal 
  float CONTROL_SIGANL = float (Kp * error   +  Kd * derivative   + Ki * e_integral_MOTOR) ;

  // motor power 
  float PWR = fabs(CONTROL_SIGANL);
  if (PWR > PWM_MAX ){
    PWR =PWM_MAX ;
  }

  // motor direction 
  int direction = RIGHT_DIR ;
  if (CONTROL_SIGANL < 0){
    direction = LEFT_DIR ;
  }
    
  // send signal to motor 
  setMotor(direction,PWR,MOTOR_PWM,MOTOR_DIR);

  e_prev_MOTOR = error;
/*
  if ( Position_MOTOR == (SET_POINT))
  {STOP_MOTOR( MOTOR_PWM,  MOTOR_DIR);} 
  else if(Position_MOTOR == (SET_POINT)+1)
  {STOP_MOTOR(MOTOR_PWM, MOTOR_DIR);} 
*/
/*
  Serial.print(190);
  Serial.print("  , ");
  Serial.print(0);
   Serial.print("  , ");
*/
 // Serial.print(SET_POINT);
 // Serial.print(" ");
 /*
  Serial.print(pos);
  Serial.println();
  */
}

void setMotor(int dir, int pwmVal, int pwm, int in1){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);  //Right Dir
 
  }
  else if(dir == -1){
    digitalWrite(in1,LOW); //Right Dir
   
  }
  else{
    digitalWrite(in1,LOW);
   analogWrite(pwm,0);
  }  
}



