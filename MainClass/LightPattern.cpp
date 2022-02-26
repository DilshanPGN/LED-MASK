#include <Arduino.h>
#include "LightPattern.h"


LightPattern::LightPattern(int ledPin ) {  
  _ledPin = ledPin;

  //setup
    matrix.begin();
    matrix.setBrightness(50);
}

void LightPattern::drawMouthPattern(const bool image_addr[]){
  matrix.clear();

  for(int x = 0; x<width; x++){
      for(int y = 0; y<height; y++){
        bool light = image_addr[x+y*width];
  
        if (light) {
         matrix.drawPixel(x, y, matrix.Color(colorRed,colorGreen,colorBlue));  
        }
      }
    }

  \
  

    
    matrix.show();
}

void LightPattern::printMouthPattern(float vol){
  if(vol < 250){
      if (silent == false) {
        silenttimer = millis() + 5000;
        silent = true;
        drawMouthPattern(mount_0);
      } else {
        if (silenttimer < millis()) {
          matrix.clear();
          matrix.show();
        }
      }
  } else if(vol < 325){
      silent = false;
      drawMouthPattern(mount_1);
  } else if(vol < 400){
      silent = false;
      drawMouthPattern(mount_2);
  } else if(vol < 475){
      silent = false;
      drawMouthPattern(mount_3);
  } else if(vol < 550){
      silent = false;
      drawMouthPattern(mount_4);
  } else {   
      silent = false;
      drawMouthPattern(mount_5);
  }
}
