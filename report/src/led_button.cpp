#include<Arduino.h>
int LedPin=13; //Đèn led tại pin 13
int InPin=2; //Nút bấm tại pin 2
int val=0; // Dùng để lưu tín hiệu từ digitalRead
void setup(){
	pinMode(LedPin,OUTPUT); // Đặt pin 13 là output
	pinMode(InPin,INPUT); // Đặt pin 2 là input (Nút bấm)
}
void loop(){
	val=digitalRead(inPin); //val=tín hiệu từ pin 2
	digitalRead(LedPin,val); 
}