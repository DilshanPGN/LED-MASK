#include <Arduino.h>
#include "Mic.h"
Mic::Mic(byte micPin) {
  _micPin = micPin;
}

float Mic::getVolume(){
  
  const uint16_t samples = 128;
  float nvol = 0;
  int previous_peak = -1;
  
  for (int i = 0; i<samples; i++){
      auto analog = analogRead(_micPin);
      auto micline = abs(analog - 512);

      nvol = max(micline, nvol);
  }

  vol = (nvol + 1.0*vol)/2.0;
  return vol;

}
