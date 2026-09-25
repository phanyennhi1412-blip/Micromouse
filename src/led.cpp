#include <Arduino.h>
void setup(){
  pinMode(PC13,OUTPUT);
}
void loop(){
  digitalWrite(PC13,HIGH);//Led tắt
  delay(50);
  digitalWrite(PC13,LOW);//Led bật 
  delay(50);
}
