
#include "Mic.h"
#include "LightPattern.h"

Mic mic(A0);
LightPattern pattern(6);

float vol;
String patternName = "pattern1";


void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
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

      if(isColors(serialInput)){
        changeLedColors(serialInput);
      }else if(isBrightness(serialInput)){
        changeBrightness(serialInput);
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

bool isColors(String input){
  String firstLetter = input.substring(0,1);
  if(firstLetter.equals("c")){
    return true;
  }else{
    return false;
  }
}

bool isBrightness(String input){
  String firstLetter = input.substring(0,1);
  if(firstLetter.equals("b")){
    return true;
  }else{
    return false;
  }
}

void changeBrightness(String val){

  int intVal = val.substring(1,val.length()).toInt();
  pattern.setBrightnessValue(intVal);
  
  
}


void changeLedColors(String s){

  int redCounter = 0;
  int greenCounter = 0;
  int blueCounter = 0;

  String strForRed = s.substring(1,s.length());
  for(int i = 0 ; i<strForRed.length() ; i++){
    if(strForRed.charAt(i)!=','){
      redCounter++;
    }else{
      break;
    }
  }

  String strForGreen = strForRed.substring((redCounter+1),strForRed.length());
  for(int i = 0 ; i<strForGreen.length() ; i++){
    if(strForGreen.charAt(i)!=','){
      greenCounter++;
    }else{
      break;
    }
  }

  String strForBlue = strForGreen.substring((greenCounter+1),strForGreen.length());
  blueCounter = strForBlue.length();

  
  

  int redInt = strForRed.substring(0,redCounter).toInt();
  int greenInt = strForGreen.substring(0,greenCounter).toInt();
  int blueInt = strForBlue.substring(0,blueCounter).toInt();


  pattern.changeLedColors(redInt , greenInt , blueInt);
}
