#include <EEPROM.h>


#include "Mic.h"
#include "LightPattern.h"

Mic mic(A0);
LightPattern pattern(5);

float vol;
String patternName = "pattern1";

//addresses
uint8_t addrPatternNo = 1;
uint8_t addrBrightness = 2;
uint8_t addrColorRed = 3;
uint8_t addrColorGreen = 4;
uint8_t addrColorBlue = 5;

//valuesFrom EEPROM
uint8_t eepromPatternNo;
uint8_t eepromBrightness;
uint8_t eepromRed;
uint8_t eepromGreen;
uint8_t eepromBlue;



void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  
  eepromPatternNo = EEPROM.read(addrPatternNo);
  eepromBrightness = EEPROM.read(addrBrightness);
  eepromRed = EEPROM.read(addrColorRed);
  eepromGreen = EEPROM.read(addrColorGreen);
  eepromBlue = EEPROM.read(addrColorBlue);

  if(eepromPatternNo==1){
    patternName = "pattern1";
  }else if(eepromPatternNo==2){
    patternName = "pattern2";
  }

  //change colors
  String colorChangeCommand = String("c")+eepromRed+String(",")+eepromGreen+String(",")+eepromBlue;
  changeLedColors(colorChangeCommand);

  //change Brightness
  String brighnessChangeCommand = String("b")+eepromBrightness;
  changeBrightness(brighnessChangeCommand);

  Serial.println(eepromPatternNo);
  Serial.println(eepromBrightness);
  Serial.println(eepromRed);
  Serial.println(eepromGreen);
  Serial.println(eepromBlue);
  Serial.println(colorChangeCommand);
  Serial.println(brighnessChangeCommand);
  
}

void loop() {
  vol = mic.getVolume();
  
  if(Serial.available() > 0){

    
    String serialInput = Serial.readString();
    serialInput.trim();
    
    if(serialInput.equals("pattern1")){
      patternName = "pattern1";
      EEPROM.write(addrPatternNo , 1);
    }else if(serialInput.equals("pattern2")){
      patternName = "pattern2";
      EEPROM.write(addrPatternNo , 2);
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
  EEPROM.write(addrBrightness , intVal);
  
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
  EEPROM.write(addrColorRed , redInt);
  EEPROM.write(addrColorGreen , greenInt);
  EEPROM.write(addrColorBlue , blueInt);

  pattern.changeLedColors(redInt , greenInt , blueInt);
}
