#ifndef Mic_h
#define Mic_h
#include "Arduino.h" 




class Mic {

  private:
    byte _micPin;
    float vol;

  public:

    Mic(byte micPin);

    float getVolume();
};

#endif
