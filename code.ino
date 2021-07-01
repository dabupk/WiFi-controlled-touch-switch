#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <EEPROM.h>

int clockPin = D7;
int dataPin = D6;
int latchPin = D5;
int touchpin0 = D0;
int touchpin1 = D1;
int touchpin2 = D2;
int touchpin3 = A0;
int button0;
int button1;
int button2;
int button3;
int swichstate0;
int swichstate1;
int swichstate2;
int swichstate3;
int touch0;
int touch1;
int touch2;
int touch3;
int touchstate0;
int touchstate1;
int touchstate2;
int touchstate3;
int state0;
int state1;
int state2;
int state3;
int pins_values=0;

char auth[] = "8efdcdb37f9546148d548d7f10908952";
char ssid[] = "Searching,Please Wait...";
char pass[] = "njmsa500";

BLYNK_WRITE(V0) 
{
  button0 = param.asInt();
}
BLYNK_WRITE(V1) 
{
  button1 = param.asInt();
}
BLYNK_WRITE(V2) 
{
  button2 = param.asInt();
}
BLYNK_WRITE(V3) 
{
  button3 = param.asInt();
}


void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(touchpin0, INPUT_PULLUP);
  pinMode(touchpin1, INPUT_PULLUP);
  pinMode(touchpin2, INPUT_PULLUP);
  EEPROM.begin(512);
  intial();
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
  trigger();
  EEPROM.commit();
  delay(5);
}

void intial(){
  touchstate0 = EEPROM.read(0);
  touchstate1 = EEPROM.read(1);
  touchstate2 = EEPROM.read(2);
  touchstate3 = EEPROM.read(3);
  trigger();
  }
  
void trigger(){
  if(switch0()){
    bitSet(pins_values,0);
    bitClear(pins_values,4);
    }
    else { 
       bitClear(pins_values,0);
       bitSet(pins_values,4);
      }
      
      if(switch1()){
    bitSet(pins_values,1);
    bitClear(pins_values,5);
    }
    else { 
       bitClear(pins_values,1);
       bitSet(pins_values,5);
      }
      
     if(switch2()){
    bitSet(pins_values,2);
    bitClear(pins_values,6);
    }
    else { 
       bitClear(pins_values,2);
       bitSet(pins_values,6);
      }
      
      if(switch3()){
    bitSet(pins_values,3);
    bitClear(pins_values,7);
    }
    else { 
       bitClear(pins_values,3);
       bitSet(pins_values,7);
      }
        digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, pins_values);
  digitalWrite(latchPin, HIGH);
  }
  
int switch0(){
  if(digitalRead(touchpin0)== HIGH){
    touch0 =  true;
    }
    else{
    touch0 =  false;  
      }
  if(touch0 != state0){
    if(state0==true){
      state0 = false;
      if(touchstate0 == true){
        touchstate0 = false;
        }
        else {
          touchstate0 = true;
          }         
      }
      else{
        state0 = true;
        if(touchstate0 == true){
        touchstate0 = false;
        }
        else {
          touchstate0 = true;
          }
        }
    }
  if(swichstate0 != touchstate0){
    swichstate0 = touchstate0;
    if(touchstate0 == true){
    Blynk.virtualWrite(V0,HIGH);
    button0 = true;
    }
    else{
      Blynk.virtualWrite(V0,LOW);
      button0 = false;
      }
    }  
  if(swichstate0 != button0){
    swichstate0 = button0;
    touchstate0 = button0;
    }
    EEPROM.write(0,swichstate0);
    return swichstate0; 
  }

  bool switch1(){
     if(digitalRead(touchpin1)== LOW){
    touch1 =  true;
    }
    else{
    touch1 =  false;  
      }
  if(touch1 != state1){
    if(state1==true){
      state1 = false;
      if(touchstate1 == true){
        touchstate1 = false;
        }
        else {
          touchstate1 = true;
          }         
      }
      else{
        state1 = true;
        if(touchstate1 == true){
        touchstate1 = false;
        }
        else {
          touchstate1 = true;
          }
        }
    }
  if(swichstate1 != touchstate1){
    swichstate1 = touchstate1;
    if(touchstate1 == true){
    Blynk.virtualWrite(V1,HIGH);
    button1 = true;
    }
    else{
      Blynk.virtualWrite(V1,LOW);
      button1 = false;
      }
    }  
  if(swichstate1 != button1){
    swichstate1 = button1;
    touchstate1 = button1;
    }
    EEPROM.write(1,swichstate1);
    return swichstate1; 
  }
  
  bool switch2(){
    if(digitalRead(touchpin2)== HIGH){
    touch2 =  true;
    }
    else{
    touch2 =  false;  
      }
  if(touch2 != state2){
    if(state2==true){
      state2 = false;
      if(touchstate2 == true){
        touchstate2 = false;
        }
        else {
          touchstate2 = true;
          }         
      }
      else{
        state2 = true;
        if(touchstate2 == true){
        touchstate2 = false;
        }
        else {
          touchstate2 = true;
          }
        }
    }
  if(swichstate2 != touchstate2){
    swichstate2 = touchstate2;
    if(touchstate2 == true){
    Blynk.virtualWrite(V2,HIGH);
    button2 = true;
    }
    else{
      Blynk.virtualWrite(V2,LOW);
      button2 = false;
      }
    }  
  if(swichstate2 != button2){
    swichstate2 = button2;
    touchstate2 = button2;
    }
    EEPROM.write(2,swichstate2);
    return swichstate2; 
  }
  
  bool switch3(){
   if(analogRead(touchpin3) > 125){
    touch3 =  true;
    }
    else{
    touch3 =  false;  
      }
  if(touch3 != state3){
    if(state3==true){
      state3 = false;
      if(touchstate3 == true){
        touchstate3 = false;
        }
        else {
          touchstate3 = true;
          }         
      }
      else{
        state3 = true;
        if(touchstate3 == true){
        touchstate3 = false;
        }
        else {
          touchstate3 = true;
          }
        }
    }
  if(swichstate3 != touchstate3){
    swichstate3 = touchstate3;
    if(touchstate3 == true){
    Blynk.virtualWrite(V3,HIGH);
    button3 = true;
    }
    else{
      Blynk.virtualWrite(V3,LOW);
      button3 = false;
      }
    }  
  if(swichstate3 != button3){
    swichstate3 = button3;
    touchstate3 = button3;
    }
    EEPROM.write(3,swichstate3);
    return swichstate3; 
  }
