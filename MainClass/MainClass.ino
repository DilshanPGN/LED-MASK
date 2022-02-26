
#include "Mic.h"
#include "LightPattern.h"

Mic mic(A0);
LightPattern pattern(6);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float vol = mic.getVolume();

  pattern.printMouthPattern(vol);
  
}
