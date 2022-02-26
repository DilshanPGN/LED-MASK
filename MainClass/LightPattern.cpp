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

//---------------------------------- Equalizer Pattern()
void LightPattern::shiftValuesOfLevelsArray(float vol){
  
  
  int volLevel =0;
    
    if(vol<100){     
      volLevel =0;
    }else if(vol<100){
      volLevel =1;
    }else if(vol<150){
      volLevel =1;
    }else if(vol<200){
      volLevel =2;
    }else if(vol<250){
      volLevel =3;
      }else if(vol<400){
      volLevel =4;
    }else if(vol<437){
      volLevel =5;
    }else if(vol<475){
      volLevel =6;
    }else if(vol<512.5){
      volLevel =7;
    }
    
    //shift data in the array to next location
    for(int arrIndex = 7; arrIndex>=1 ; arrIndex--){
      
      numberArray[arrIndex]= numberArray[arrIndex-1];        
    }
  
    //last data
    numberArray[0] = volLevel;

    //re-valuing the matrix  
    for (int col = 0 ; col<8 ; col++ ){

      int peakValue = numberArray[col];
      
      //true
      for(int row = 6; (6-row)< peakValue ; row--){ 
        equalizerPatternArray[row][col] = true;
      }
  
      //false
      for(int row = 0 ; row <= (6-peakValue) ; row++){ 
        equalizerPatternArray[row][col] = false;
      } 
    } 
}




void LightPattern::printEqualizerPattern(float vol){
  shiftValuesOfLevelsArray(vol);
  
  matrix.clear();
  for(int row =0 ; row<7 ;row++){
    for(int col =0 ; col<8 ;col++){
      

      bool light = equalizerPatternArray[row][col];
  
        if (light) {
         matrix.drawPixel(col, row, matrix.Color(colorRed,colorGreen,colorBlue));  
        }
    }
  }


  matrix.show();
}


//---------------- Change colors
void LightPattern::setRedColor(int val){
  colorRed = val;
}
void LightPattern::setGreenColor(int val){
  colorGreen = val;
}
void LightPattern::setBlueColor(int val){
  colorBlue = val;
}
