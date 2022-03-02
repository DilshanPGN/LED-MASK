#ifndef LightPattern_h
#define LightPattern_h
#include "Arduino.h" 


#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <avr/pgmspace.h>

const bool O = true;
    const bool F = false;

class LightPattern {
  
  private:

    int _ledPin      = 6;
    int width       = 8;
    int height      = 7;

    float _volume;
    //Colors
    int colorRed = 50;
    int colorGreen = 50;
    int colorBlue = 50;
    
    //pattern    
    String pattern = "pattern1";    

    bool silent = false;
    long silenttimer = 0;

    int numberArray[8]= {0,0,0,0,0,0,0,0};

    
    
    //objects
    Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(width, height, _ledPin,
    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS    + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800);

    


    //---------------------------------------- Arrays for pattern 2
    boolean equalizerPatternArray[7][8] = {
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F},
         {F,F,F,F,F,F,F,F}   
        };
    
    //------------------------------------------Arrays for mouth pattern
    const bool mount_0[56]  = {
     F , F , F , F , F , F , F , F, 
     F , F , F , F , F , F , F , F,
     F , F , F , O , O , F , F , F,
     F , F , O , F , F , O , F , F,
     F , F , F , O , O , F , F , F,
     F , F , F , F , F , F , F , F,
     F , F , F , F , F , F , F , F
    };
    
    
    const bool mount_1[56]  = {
     F , F , F , F , F , F , F , F, 
     F , F , F , F , F , F , F , F,
     F , F , O , O , O , O , F , F,
     F , O , F , F , F , F , O , F,
     F , F , O , F , F , O , F , F,
     F , F , F , O , O , F , F , F,
     F , F , F , F , F , F , F , F
    };
    
    
    const bool mount_2[56]  = {
     F , F , F , F , F , F , F , F, 
     F , F , F , O , O , F , F , F,
     F , F , O , F , F , O , F , F,
     F , O , F , F , F , F , O , F,
     F , F , O , F , F , O , F , F,
     F , F , F , O , O , F , F , F,
     F , F , F , F , F , F , F , F
    };
    
    const bool mount_3[56]  = {
     F , F , F , F , F , F , F , F, 
     F , F , O , O , O , O , F , F,
     F , O , F , F , F , F , O , F,
     O , F , F , F , F , F , F , O,
     F , O , F , F , F , F , O , F,
     F , F , O , O , O , O , F , F,
     F , F , F , F , F , F , F , F
    };
    
    
    const bool mount_4[56]  = {
     F , F , F , F , F , F , F , F, 
     F , F , O , O , O , O , F , F,
     F , O , F , F , F , F , O , F,
     O , F , F , F , F , F , F , O,
     F , O , F , F , F , F , O , F,
     F , F , O , F , F , O , F , F,
     F , F , F , O , O , F , F , F
    };
    
    
    const bool mount_5[56]  = {
     F , F , F , O , O , F , F , F, 
     F , F , O , F , F , O , F , F,
     F , O , F , F , F , F , O , F,
     O , F , F , F , F , F , F , O,
     F , O , F , F , F , F , O , F,
     F , F , O , F , F , O , F , F,
     F , F , F , O , O , F , F , F
    };

    
    
  public:

    LightPattern(int ledPin);

    void drawMouthPattern(const bool image_addr[]);
    void printMouthPattern(float vol);
    void shiftValuesOfLevelsArray(float vol);
    void printEqualizerPattern(float vol);

    void setRedColor(int val);
    void setGreenColor(int val);
    void setBlueColor(int val);
    void changeLedColors(int red , int green , int blue);
    void setBrightnessValue(int val);
    
  public:

    


    
};












    
    
        
    



#endif
