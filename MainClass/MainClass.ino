
#include "Mic.h"
#include "LightPattern.h"

Mic mic(A0);
LightPattern pattern(6);

float vol;
String patternName = "pattern1";


void setup() {
  Serial.begin(9600);
}

void loop() {
  vol = mic.getVolume();

  if(Serial.available() > 0){

    
    String serialInput = Serial.readString();
    
    serialInput.trim();
    
    if(serialInput.equals("pattern1")){
      patternName = "pattern1";
    }else if(serialInput.equals("pattern2")){
      patternName = "pattern2";
    }else{

      if(isRed(serialInput)){
        changeRedColor(serialInput);
      }else if(isGreen(serialInput)){
        changeGreenColor(serialInput);
      }else if(isBlue(serialInput)){
        changeBlueColor(serialInput);
      }
      
    }  
  }
  
  
  if(patternName.equals("pattern1")){
    pattern.printMouthPattern(vol);
  }
  else if(patternName.equals("pattern2")) {
    pattern.printEqualizerPattern(vol);
    
  }

  
}


//methods to change colour

bool isRed(String input){
  String firstLetter = input.substring(0,1);
  if(firstLetter.equals("r")){
    changeRedColor(input);
    return true;
  }else{
    return false;
  }
}

bool isGreen(String input){
  String firstLetter = input.substring(0,1);
  if(firstLetter.equals("g")){
    return true;
  }else{
    return false;
  }
}

bool isBlue(String input){
  String firstLetter = input.substring(0,1);
  if(firstLetter.equals("b")){
    return true;
  }else{
    return false;
  }
}



void changeRedColor(String input){

  int val = input.substring(1,input.length()).toInt();
  pattern.setRedColor(val);
  
}
void changeGreenColor(String input){

  int val = input.substring(1,input.length()).toInt();
  pattern.setGreenColor(val);
  
}
void changeBlueColor(String input){

  int val = input.substring(1,input.length()).toInt();
  pattern.setBlueColor(val);
  
}
