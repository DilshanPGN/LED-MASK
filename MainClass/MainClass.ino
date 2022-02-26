
#include "Mic.h"

Mic mic(A0);


void setup() {
  Serial.begin(9600);
}

void loop() {
  float result1 = mic.getVolume();
  Serial.println(result1);
}
