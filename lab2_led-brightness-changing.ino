#include "TimerThree.h"
const int red = 4;
const int yellow = 3;
const int green = 2; 
const int resistor = A0;
const double pi = 3.14;
double k;
double t;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(resistor, INPUT);
  Timer3.initialize(16000);
  Timer3.attachInterrupt(func);  
}

void func() {
  t = millis()/double(1000);
  k = analogRead(resistor)/int(100);
  analogWrite(red,255*(sin(k*t)+1)/2);
  analogWrite(yellow, 255*(sin(k*t+2*pi/3)+1)/2);
  analogWrite(green,255*(sin(k*t+4*pi/3)+1)/2);
}


void loop() {    
}
