#include <MsTimer2.h>    
 
int a = 0;
int b;
int pinInterrupt=2;
void onTimer()
{ 
  Serial.print("timer ");
  a++;
  Serial.println(a);
  b=a-'0';
  digitalWrite(2,b&0x1);
    digitalWrite(3,(b>>1)&0x1);
    digitalWrite(4,(b>>2)&0x1);
    digitalWrite(5,(b>>3)&0x1);
}
 void Onchange()
 {
   a=0;
 }
void setup()
{ 
  Serial.begin(9600); 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  MsTimer2::set(800, onTimer);
  MsTimer2::start(); 
   attachInterrupt( digitalPinToInterrupt(pinInterrupt), Onchange, CHANGE);
}
 
void loop()
{
  
}