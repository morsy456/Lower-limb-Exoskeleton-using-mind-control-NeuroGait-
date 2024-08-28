#include <util/atomic.h> // For the ATOMIC_BLOCK macro
#include "INTERFACE.h"
#include "PathPlanning.h"

#define cyclelength 5000 //millis 
int Position_MOTOR_1 = 0;
long T_prev_MOTOR_1 = 0;
float e_prev_MOTOR_1 = 0;
float e_integral_MOTOR_1 = 0;

int Position_MOTOR_2 = 0;
long T_prev_MOTOR_2 = 0;
float e_prev_MOTOR_2 = 0;
float e_integral_MOTOR_2 = 0;

int Position_MOTOR_3 = 0;
long T_prev_MOTOR_3 = 0;
float e_prev_MOTOR_3 = 0;
float e_integral_MOTOR_3 = 0;

int Position_MOTOR_4 = 0; 
long T_prev_MOTOR_4 = 0;
float e_prev_MOTOR_4 = 0;
float e_integral_MOTOR_4 = 0;

volatile double temp_1, counter_1 = 0;
volatile double temp_2, counter_2 = 0;
volatile double temp_3, counter_3 = 0;
volatile double temp_4, counter_4 = 0;

/**** interface angles ****/

int SET_POINT_1 = 0;
int SET_POINT_2 = 0;
int SET_POINT_3 = 0;
int SET_POINT_4 = 0;
unsigned long startTime;


void setup() {
  MOTOR_INIT();
  // Encoder code
  Serial.begin(9600);

  Encoder_INIT();
  startTime=millis();
}

void loop() {
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
/*
  Serial.println(temp_1);
  Serial.println(temp_2);
  Serial.println(temp_3);
  Serial.println(temp_4);
  
*/

// Repeat the gait cycle every second
  float elapsedTime = ((millis() - startTime) % cyclelength); // Convert to seconds
  
  
  
   elapsedTime=float(2*(elapsedTime/cyclelength)) ;

  calculateTrajectory(elapsedTime);
  //Serial.println(elapsedTime);
  SET_POINT_1 = angles[1];//left knee   1
  SET_POINT_2 = angles[0];//left hip    0
  SET_POINT_3 = angles[2];//right hip   2
  SET_POINT_4 = angles[3];//right knee  3

  PID_ANGEL_MOTION(SET_POINT_1, counter_1, Position_MOTOR_1, T_prev_MOTOR_1, e_prev_MOTOR_1, e_integral_MOTOR_1, Kp_MOTOR_1, Ki_MOTOR_1, Kd_MOTOR_1, MOTOR_PWM_1, MOTOR_DIR_1, MAX_1);
  PID_ANGEL_MOTION(SET_POINT_2, counter_2, Position_MOTOR_2, T_prev_MOTOR_2, e_prev_MOTOR_2, e_integral_MOTOR_2, Kp_MOTOR_2, Ki_MOTOR_2, Kd_MOTOR_2, MOTOR_PWM_2, MOTOR_DIR_2,MAX_2 );
  PID_ANGEL_MOTION(SET_POINT_3, counter_3, Position_MOTOR_3, T_prev_MOTOR_3, e_prev_MOTOR_3, e_integral_MOTOR_3, Kp_MOTOR_3, Ki_MOTOR_3, Kd_MOTOR_3, MOTOR_PWM_3, MOTOR_DIR_3,MAX_3 );
  PID_ANGEL_MOTION(SET_POINT_4, counter_4, Position_MOTOR_4, T_prev_MOTOR_4, e_prev_MOTOR_4, e_integral_MOTOR_4, Kp_MOTOR_4, Ki_MOTOR_4, Kd_MOTOR_4, MOTOR_PWM_4, MOTOR_DIR_4,MAX_4 );

 // Serial.print(190);
 // Serial.print("  , ");
 // Serial.print(0);
   //Serial.print("  , ");
  Serial.print(" ");
  Serial.print(SET_POINT_1);
  Serial.print(" ");
 Serial.print(SET_POINT_2);
 //Serial.println();
  Serial.print(" ");
   Serial.print(SET_POINT_3);
  Serial.print(" ");
  Serial.print(SET_POINT_4);
 // Serial.println();
   Serial.print(" ");
  
 
  delay(10);
  // Calculate trajectory based on gait cycle
  
  }
