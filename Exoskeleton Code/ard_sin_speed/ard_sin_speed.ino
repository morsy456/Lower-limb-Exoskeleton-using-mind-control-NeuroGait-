// Define constants
const float WHEEL_CIRCUMFERENCE = 0.52;  // Example: wheel circumference in meters
const int ENCODER_RESOLUTION = 600;          // Example: encoder pulses per revolution
const unsigned long TIME_INTERVAL = 10;      // Example: time interval in milliseconds
int TIME_INTERVAL1 = -10;
int sample_T=10;

//motor pins
#define MOTOR_PWM 6
#define MOTOR_DIR 8
//Encoder pins
#define Interrupt_2 2
#define Interrupt_3 3


#define speed_Delay 10
volatile unsigned int temp, counter = 0;
unsigned long previousMillis = 0;


int pwmValues[] = { 0.0, 1.6, 3.2, 4.8, 6.4, 8.0, 9.6, 11.2, 12.8, 14.4, 16.0, 17.6, 19.2, 20.8, 22.4, 24.0, 25.6, 27.2, 28.8, 30.4, 32.0, 33.6, 35.2, 36.8, 38.4, 40.0, 41.6, 43.1, 44.7, 46.3, 47.9, 49.5, 51.0, 52.6, 54.2, 55.7, 57.3, 58.9, 60.4, 62.0, 63.5, 65.1, 66.6, 68.2, 69.7, 71.3, 72.8, 74.4, 75.9, 77.4, 79.0, 80.5, 82.0, 83.5, 85.0, 86.5, 88.1, 89.6, 91.1, 92.6, 94.1, 95.5, 97.0, 98.5, 100.0, 101.5, 102.9, 104.4, 105.9, 107.3, 108.8, 110.2, 111.7, 113.1, 114.6, 116.0, 117.4, 118.8, 120.3, 121.7, 123.1, 124.5, 125.9, 127.3, 128.7, 130.0, 131.4, 132.8, 134.2, 135.5, 136.9, 138.2, 139.6, 140.9, 142.3, 143.6, 144.9, 146.2, 147.5, 148.8, 150.1, 151.4, 152.7, 154.0, 155.3, 156.6, 157.8, 159.1, 160.3, 161.6, 162.8, 164.0, 165.3, 166.5, 167.7, 168.9, 170.1, 171.3, 172.5, 173.7, 174.8, 176.0, 177.2, 178.3, 179.5, 180.6, 181.7, 182.8, 184.0, 185.1, 186.2, 187.3, 188.4, 189.4, 190.5, 191.6, 192.6, 193.7, 194.7, 195.7, 196.8, 197.8, 198.8, 199.8, 200.8, 201.8, 202.8, 203.7, 204.7, 205.6, 206.6, 207.5, 208.4, 209.4, 210.3, 211.2, 212.1, 213.0, 213.8, 214.7, 215.6, 216.4, 217.3, 218.1, 218.9, 219.8, 220.6, 221.4, 222.2, 222.9, 223.7, 224.5, 225.2, 226.0, 226.7, 227.5, 228.2, 228.9, 229.6, 230.3, 231.0, 231.7, 232.3, 233.0, 233.6, 234.3, 234.9, 235.5, 236.1, 236.7, 237.3, 237.9, 238.5, 239.0, 239.6, 240.1, 240.7, 241.2, 241.7, 242.2, 242.7, 243.2, 243.7, 244.2, 244.6, 245.1, 245.5, 245.9, 246.3, 246.8, 247.2, 247.5, 247.9, 248.3, 248.7, 249.0, 249.3, 249.7, 250.0, 250.3, 250.6, 250.9, 251.2, 251.5, 251.7, 252.0, 252.2, 252.4, 252.7, 252.9, 253.1, 253.3, 253.5, 253.6, 253.8, 253.9, 254.1, 254.2, 254.3, 254.4, 254.5, 254.6, 254.7, 254.8, 254.8, 254.9, 254.9, 255.0, 255.0, 255.0, 255.0, 255.0, 255.0, 254.9, 254.9, 254.8, 254.8, 254.7, 254.6, 254.5, 254.4, 254.3, 254.2, 254.1, 253.9, 253.8, 253.6, 253.5, 253.3, 253.1, 252.9, 252.7, 252.4, 252.2, 252.0, 251.7, 251.5, 251.2, 250.9, 250.6, 250.3, 250.0, 249.7, 249.3, 249.0, 248.7, 248.3, 247.9, 247.5, 247.2, 246.8, 246.3, 245.9, 245.5, 245.1, 244.6, 244.2, 243.7, 243.2, 242.7, 242.2, 241.7, 241.2, 240.7, 240.1, 239.6, 239.0, 238.5, 237.9, 237.3, 236.7, 236.1, 235.5, 234.9, 234.3, 233.6, 233.0, 232.3, 231.7, 231.0, 230.3, 229.6, 228.9, 228.2, 227.5, 226.7, 226.0, 225.2, 224.5, 223.7, 222.9, 222.2, 221.4, 220.6, 219.8, 218.9, 218.1, 217.3, 216.4, 215.6, 214.7, 213.8, 213.0, 212.1, 211.2, 210.3, 209.4, 208.4, 207.5, 206.6, 205.6, 204.7, 203.7, 202.8, 201.8, 200.8, 199.8, 198.8, 197.8, 196.8, 195.7, 194.7, 193.7, 192.6, 191.6, 190.5, 189.4, 188.4, 187.3, 186.2, 185.1, 184.0, 182.8, 181.7, 180.6, 179.5, 178.3, 177.2, 176.0, 174.8, 173.7, 172.5, 171.3, 170.1, 168.9, 167.7, 166.5, 165.3, 164.0, 162.8, 161.6, 160.3, 159.1, 157.8, 156.6, 155.3, 154.0, 152.7, 151.4, 150.1, 148.8, 147.5, 146.2, 144.9, 143.6, 142.3, 140.9, 139.6, 138.2, 136.9, 135.5, 134.2, 132.8, 131.4, 130.0, 128.7, 127.3, 125.9, 124.5, 123.1, 121.7, 120.3, 118.8, 117.4, 116.0, 114.6, 113.1, 111.7, 110.2, 108.8, 107.3, 105.9, 104.4, 102.9, 101.5, 100.0, 98.5, 97.0, 95.5, 94.1, 92.6, 91.1, 89.6, 88.1, 86.5, 85.0, 83.5, 82.0, 80.5, 79.0, 77.4, 75.9, 74.4, 72.8, 71.3, 69.7, 68.2, 66.6, 65.1, 63.5, 62.0, 60.4, 58.9, 57.3, 55.7, 54.2, 52.6, 51.0, 49.5, 47.9, 46.3, 44.7, 43.1, 41.6, 40.0, 38.4, 36.8, 35.2, 33.6, 32.0, 30.4, 28.8, 27.2, 25.6, 24.0, 22.4, 20.8, 19.2, 17.6, 16.0, 14.4, 12.8, 11.2, 9.6, 8.0, 6.4, 4.8, 3.2, 1.6, 0.0 };
int numValues = sizeof(pwmValues) / sizeof(pwmValues[0]);

float speed = 0.0;
float voltage = 0.0;

void setup() {
  // code motor
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_DIR, OUTPUT);

  //encoder code

  Serial.begin(9600);
  pinMode(Interrupt_2, INPUT_PULLUP);  // internal pullup input pin 2
  pinMode(Interrupt_3, INPUT_PULLUP);  // internalเป็น pullup input pin 3
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);  // suppose to be 2
    //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);  // suppose to be 3
}

void loop() {



  d1();
  d2();
}


void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if (digitalRead(3) == LOW) {
    counter++;
  } else {
    counter--;
  }
}
void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if (digitalRead(2) == LOW) {
    counter--;
  } else {
    counter++;
  }
}



void d1() {

  digitalWrite(MOTOR_DIR, LOW);
  for (int i = 0; i < numValues; i++) {
    analogWrite(MOTOR_PWM, pwmValues[i]);  // Set PWM output
    delay(speed_Delay);

    unsigned long currentMillis = millis();

    // Calculate speed every TIME_INTERVAL milliseconds
    if (currentMillis - previousMillis >= TIME_INTERVAL) {
      // Calculate rotations
      counter=65534-counter;
      float rotations = counter / float(ENCODER_RESOLUTION);
      
      // Calculate distance traveled
      float distance = rotations * WHEEL_CIRCUMFERENCE;

      // Calculate speed (m/s)
      speed = distance / (TIME_INTERVAL / 1000.0);  // Convert milliseconds to seconds

      // Print speed
      //Serial.print("Speed: ");
      Serial.print(speed);
      Serial.print("  ");

      // Reset pulse count and update previousMillis
      counter = 0;
      previousMillis = currentMillis;
    }

    //encoder code
    // Send the value of counter


    voltage = float((pwmValues[i] * 24.0) / 255.0);
    //Serial.print("angle=");
    //Serial.print(counter);
    //Serial.print(" , ");
    //Serial.print("voltage=");
    Serial.print(voltage);
    Serial.print("  ");
    TIME_INTERVAL1= TIME_INTERVAL1 + sample_T;
    Serial.println(TIME_INTERVAL1);
  }
}
void d2() {
  digitalWrite(MOTOR_DIR, HIGH);
  for (int i = numValues; i > -1; i--) {
    analogWrite(MOTOR_PWM, pwmValues[i]);  // Set PWM output
    delay(speed_Delay);

    unsigned long currentMillis = millis();

    // Calculate speed every TIME_INTERVAL milliseconds
    if (currentMillis - previousMillis >= TIME_INTERVAL) {
      // Calculate rotations
      //counter=65534-counter;
      float rotations = counter / float(ENCODER_RESOLUTION);

      // Calculate distance traveled
      float distance = rotations * WHEEL_CIRCUMFERENCE;

      // Calculate speed (m/s)
      speed = distance / (TIME_INTERVAL / 1000.0);  // Convert milliseconds to seconds
      speed = speed * -1;
      // Print speed
      //Serial.print("Speed: ");
      Serial.print(speed );
      Serial.print("  ");

      // Reset pulse count and update previousMillis
      counter = 0;
      previousMillis = currentMillis;
    }

    //encoder code
    // Send the value of counter


    voltage = float((pwmValues[i] * 24.0) / 255.0);
    //Serial.print("angle=");
    //Serial.print(counter);
    //Serial.print(" , ");
    //Serial.print("voltage=");
    Serial.print(voltage * -1);
    Serial.print("  ");
    TIME_INTERVAL1=TIME_INTERVAL1+sample_T;
    Serial.println(TIME_INTERVAL1);
  }
}
