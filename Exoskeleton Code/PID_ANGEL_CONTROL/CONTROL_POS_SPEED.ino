
/*
//GeeKee CeeBee
// ************ DEFINITIONS************
float kp = 0.02;
float ki = 0.00015 ;
float kd = 0;

unsigned long t;
unsigned long t_prev = 0;

const byte interruptPinA = 2;
const byte interruptPinB = 3;
volatile long EncoderCount = 0;
const byte PWMPin = 6;
const byte DirPin1 = 7;
const byte DirPin2 = 8;

volatile unsigned long count = 0;
unsigned long count_prev = 0;

float Theta, RPM, RPM_d;
float Theta_prev = 0;
int dt;

float RPM_max = 230;

#define pi 3.1416

float Vmax = 6;
float Vmin = -6;
float V = 0.1;
float e, e_prev = 0, inte, inte_prev = 0;

//**********FUNCTIONS******************
//     Void ISR_EncoderA
//     Void ISR_EncoderB
//     Void Motor Driver Write
//     Timer Interrupt
//*************************************
void ISR_EncoderA() {
  bool PinB = digitalRead(interruptPinB);
  bool PinA = digitalRead(interruptPinA);

  if (PinB == LOW) {
    if (PinA == HIGH) {
      EncoderCount++;
    }
    else {
      EncoderCount--;
    }
  }

  else {
    if (PinA == HIGH) {
      EncoderCount--;
    }
    else {
      EncoderCount++;
    }
  }
}



void ISR_EncoderB() {
  bool PinB = digitalRead(interruptPinA);
  bool PinA = digitalRead(interruptPinB);

  if (PinA == LOW) {
    if (PinB == HIGH) {
      EncoderCount--;
    }
    else {
      EncoderCount++;
    }
  }

  else {
    if (PinB == HIGH) {
      EncoderCount++;
    }
    else {
      EncoderCount--;
    }
  }
}


float sign(float x) {
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

//***Motor Driver Functions*****

void WriteDriverVoltage(float V, float Vmax) {
  int PWMval = int(255 * abs(V) / Vmax);
  if (PWMval > 255) {
    PWMval = 255;
  }
  if (V > 0) {
    digitalWrite(DirPin1, HIGH);
    digitalWrite(DirPin2, LOW);
  }
  else if (V < 0) {
    digitalWrite(DirPin1, LOW);
    digitalWrite(DirPin2, HIGH);
  }
  else {
    digitalWrite(DirPin1, LOW);
    digitalWrite(DirPin2, LOW);
  }
  analogWrite(PWMPin, PWMval);
}

void setup() {
  Serial.begin(9600);
  pinMode(interruptPinA, INPUT_PULLUP);
  pinMode(interruptPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPinA), ISR_EncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPinB), ISR_EncoderB, CHANGE);
  pinMode(DirPin1, OUTPUT);
  pinMode(DirPin2, OUTPUT);

  //timer code
/*using timers in arduino , from datasheet ,  

 --> timer 0 : 8 bits 
 --> timer 1 : 16 bits 
 --> timer 2 : 8 bits

 ** time stop = delta t = 50 ms 
 equation since arduino frequency is 16MHz
 prescaler could  be any number of these.
 prescaler = 1  ,  8  ,  64  , 256  ,  1024  

  output compare value = (16 MHz / (1/(0.05 ms)) * (prescaler)) - 1 ;
  you should get inger value from this equation so by applying a 64
  we get 
  output compare value = (16 MHz / (1/(0.05 ms)) * (64)) - 1 ;
  = 12499 --> its a good result.
*/
/* 
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 12499; //Prescaler = 64
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS11 | 1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void loop() {
  if (count > count_prev) {
    t = millis();
    Theta = EncoderCount / 900.0;
    dt = (t - t_prev);
    RPM_d = RPM_max * (sin(2 * pi * 0.005 * t / 1000.0))
        * sign(sin(2 * pi * 0.05 * t / 1000.0));
    
    if (t / 1000.0 > 100) {
      RPM_d = 0;
    }
    
    RPM = (Theta - Theta_prev) / (dt / 1000.0) * 60;
    e = RPM_d - RPM;
    inte = inte_prev + (dt * (e + e_prev) / 2);
    V = kp * e + ki * inte + (kd * (e - e_prev) / dt) ;
    
    if (V > Vmax) {
      V = Vmax;
      inte = inte_prev;
    }
    if (V < Vmin) {
      V = Vmin;
      inte = inte_prev;
    }


    WriteDriverVoltage(V, Vmax);

    Serial.print(RPM_d); Serial.print(" \t");
    Serial.print(RPM); Serial.print(" \t ");
    Serial.print(V); Serial.print("\t  ");
    Serial.print(e); Serial.println("  ");

    Theta_prev = Theta;
    count_prev = count;
    t_prev = t;
    inte_prev = inte;
    e_prev = e;
  }

}



ISR(TIMER1_COMPA_vect) {
  count++;
  Serial.print(count * 0.05); Serial.print(" \t");
}
*/