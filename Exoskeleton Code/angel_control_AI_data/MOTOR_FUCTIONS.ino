
float VOLTAGE_EQUATION(float FLOAT_LOCAL_MOTOR_PWM_SPEED )
{
   voltage=float((MOTOR_PWM_SPEED*12.0)/255.0) ;
   
   return voltage;
}

float ANGLE_OF_ROTATION_WITH_VOLT(float counter)
{
  float angle = counter * 0.6 * GEAR_RATIO ;
  return angle;
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




