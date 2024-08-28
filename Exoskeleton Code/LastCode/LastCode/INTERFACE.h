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
#define Interrupt_1 19      // knee left
#define Interrupt_2 10

#define Interrupt_3 18      // hip left
#define Interrupt_4 11

// arduino 2
#define Interrupt_5 2       // hip right 
#define Interrupt_6 12

#define Interrupt_7 3       // knee right
#define Interrupt_8 13

/* Motor Direction Definitions */
#define RIGHT_DIR  1
#define LEFT_DIR  -1

//Motor Speeds 
#define MOTOR_PWM_SPEED 200
#define STOP_MOTOR_SPEED 0

#define ANGLE_REQUIRED 30
// gear ratio of the motor shaft to the encoder shaft rotation  so when we calc the rotation of the shaft the encoder must be * 4.91
#define GEAR_RATIO  0.1   //  (11/50) suppose to be this  

#define steady_Delay_D_2 1000
#define steady_Delay_D_1 700
#define speed_Delay 500


#define MAX_1 100
#define Kp_MOTOR_1  2 //15
#define Ki_MOTOR_1  0.8  //0
#define Kd_MOTOR_1  0.2  //1

#define MAX_2 100
#define Kp_MOTOR_2  2 //15
#define Ki_MOTOR_2  0.8  //0
#define Kd_MOTOR_2  0.2  //1

#define MAX_3 100
#define Kp_MOTOR_3  2 //15
#define Ki_MOTOR_3  0.8  //0
#define Kd_MOTOR_3  0.2 //1

#define MAX_4  100
#define Kp_MOTOR_4  2 //15
#define Ki_MOTOR_4  0.8  //0
#define Kd_MOTOR_4  0.2  //1



/*************** Constants ******************/
#define pi 3.1416



/*************** Motor Motion **************/

void STOP_MOTOR(int MOTOR_PWM, int MOTOR_DIR);
//void MOVE_MOTOR_LEFT_DIR();
//void MOVE_MOTOR_RIGHT_DIR();
