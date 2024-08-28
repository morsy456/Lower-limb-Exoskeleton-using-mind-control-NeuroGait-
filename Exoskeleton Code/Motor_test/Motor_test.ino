
/*************** PINS **************/
//motor pins 
//arduino 1
#define MOTOR_PWM_1 6 
#define MOTOR_DIR_1 17
#define MOTOR_PWM_2 7 
#define MOTOR_DIR_2 16 

//arduino 2
#define MOTOR_PWM_3 8
#define MOTOR_DIR_3 4
#define MOTOR_PWM_4 9 
#define MOTOR_DIR_4 5

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

/* Motor Direction Definitions */
#define RIGHT_DIR  1
#define LEFT_DIR  -1

//Motor Speeds 
#define MOTOR_PWM_SPEED 43
#define STOP_MOTOR_SPEED 0

#define ANGLE_REQUIRED 30
// gear ratio of the motor shaft to the encoder shaft rotation  so when we calc the rotation of the shaft the encoder must be * 4.91
#define GEAR_RATIO  0.1   //  (11/50) suppose to be this  

#define steady_Delay_D_2 1000
#define steady_Delay_D_1 700
#define speed_Delay 500

void setup() {
  // put your setup code here, to run once:

MOTOR_INIT();


}

void loop() {
  // put your main code here, to run repeatedly:
MOVE_MOTOR_RIGHT_DIR();
delay ( 1000);
MOVE_MOTOR_LEFT_DIR();
delay ( 1000);

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