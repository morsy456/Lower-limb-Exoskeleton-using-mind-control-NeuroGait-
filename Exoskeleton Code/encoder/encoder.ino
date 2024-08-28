#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENCA 18 // YELLOW
#define ENCB 10 // WHITE

volatile int posi = 0; // specify posi as volatile

void setup() {

  Serial.begin(9600);

  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
}

void loop() {
  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  int pos = 0; 
  
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }

  Serial.println(pos);
  delay(100); // Add a small delay to make the output readable
}

void readEncoder() {
  int b = digitalRead(ENCB);
  if (b > 0) {
    posi++;
  } else {
    posi--;
  }
}
