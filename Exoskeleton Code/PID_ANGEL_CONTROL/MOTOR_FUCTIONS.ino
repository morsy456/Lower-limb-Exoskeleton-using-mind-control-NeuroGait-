
double VOLTAGE_EQUATION(double FLOAT_LOCAL_MOTOR_PWM_SPEED )
{
  double voltage = double((MOTOR_PWM_SPEED*12.0)/255.0) ;
   
   return voltage;
}
/*
double ANGLE_OF_ROTATION_WITH_VOLT(float counter)
{
  double angle = counter * 0.6 * GEAR_RATIO ;
  return angle;
}
*/


void MOTOR_SPEED_DIR_MOTION(int MOTOR_PIN , int MOTOR_PWM_PIN ,int PWM_Value , char Direction)
{
    analogWrite(MOTOR_PWM_PIN, PWM_Value); // control the speed  
 
    switch (MOTOT_PWM_PIN>0  &&  MOTOT_PWM_PIN < 255) {

    case "R": digitalWrite(MOTOR_DIR, RIGHT_DIR);               break;   
    case "L": digitalWrite(MOTOR_DIR, LEFT_DIR);                break;
    case "S": analogWrite(MOTOR_PWM_PIN, STOP_MOTOR_SPEED);     break;           
    }  
}

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

void STOP_MOTOR()
{
  digitalWrite(MOTOR_DIR, LOW);
  analogWrite(MOTOR_PWM, STOP_MOTOR_SPEED); // control the speed
}

void WriteDriverVoltage(float V, float Vmax) {
  int PWMval = int(255 * abs(V) / Vmax);
  
  if (PWMval > 255) {
    PWMval = 255;
  }

  if (V > 0) {
  MOVE_MOTOR_LEFT_DIR();
  }
 
  else if (V < 0) {
    MOVE_MOTOR_RIGHT_DIR();
  }
 
  else{
    STOP_MOTOR();
  }
  analogWrite(MOTOR_PWM, PWMval);

}



