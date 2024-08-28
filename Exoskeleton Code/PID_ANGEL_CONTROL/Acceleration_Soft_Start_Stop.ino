
void Accelerate_D_1(){
  for (int speed = 0; speed <= 255; speed++) {
    digitalWrite(MOTOR_DIR, HIGH);
    analogWrite(MOTOR_PWM, speed); // control the speed
      
   // voltage=(speed*12.0)/255.0 ;
    float angle = counter * 0.6 * GEAR_RATIO ;

    Serial.print(angle);
     Serial.print("          ");
    Serial.print(counter);
    Serial.print("          ");
  //  Serial.print(voltage);

    delay(speed_Delay);
      //  Serial.print(" , ");
 //   Serial.print("voltage=");
    
    Serial.println();
  }
}
void decelerate_D_1(){
  for (int speed = 255; speed >= 0; speed--) {
    digitalWrite(MOTOR_DIR, HIGH);
    analogWrite(MOTOR_PWM, speed); // control the speed
    delay(speed_Delay);
   //    voltage=float((speed*12.0)/255.0) ;

//    Serial.print("angle=");
    Serial.print(counter);
//    Serial.print(" , ");
//    Serial.print("voltage=");
   // Serial.print(voltage);
     Serial.println();
  }
}
void Accelerate_D_2(){
  for (int speed = 0; speed <= 255; speed++) {
    digitalWrite(MOTOR_DIR, LOW);
    analogWrite(MOTOR_PWM, speed); // control the speed
    delay(speed_Delay);
   // voltage=float((speed*12.0)/255.0) ;
    //Serial.print("angle=");
    Serial.print(counter);
    //Serial.print(" , ");
    //Serial.print("voltage=");
   // Serial.print(voltage);
     Serial.println();
  }
}
void decelerate_D_2(){
  for (int speed = 255; speed >= 0; speed--) {
    digitalWrite(MOTOR_DIR, LOW);
    analogWrite(MOTOR_PWM, speed); // control the speed
    delay(speed_Delay);
  //  voltage=float((speed*12.0)/255.0) ;
    //Serial.print("angle=");
    Serial.print(counter);
    //Serial.print(" , ");
    //Serial.print("voltage=");
   // Serial.print(voltage);
     Serial.println();
  }
}
