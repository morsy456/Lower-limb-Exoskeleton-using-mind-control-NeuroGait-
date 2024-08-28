//motor pins 
#define MOTOR_PWM 6 
#define MOTOR_DIR 8 
/* Motor Direction Definitions */
#define RIGHT_DIR  0
#define LEFT_DIR  1
//Encoder pins
#define Interrupt_2 2
#define Interrupt_3 3

#define MOTOR_PWM_SPEED 43
#define STOP_MOTOR_SPEED 0


#define ANGLE_REQUIRED 30
// gear ratio of the motor shaft to the encoder shaft rotation  so when we calc the rotation of the shaft the encoder must be * 4.91
#define GEAR_RATIO  0.203704


#define steady_Delay_D_2 1000
#define steady_Delay_D_1 700
#define speed_Delay 500

void decelerate_D_2();
void Accelerate_D_2();
void decelerate_D_1();
void Accelerate_D_1();

void ai1() ;
void ai0() ;

void STOP_MOTOR();
void MOVE_MOTOR_LEFT_DIR();
void MOVE_MOTOR_RIGHT_DIR();

float ANGLE_OF_ROTATION_WITH_VOLT(float counter);
float VOLTAGE_EQUATION(float FLOAT_LOCAL_MOTOR_PWM_SPEED );
