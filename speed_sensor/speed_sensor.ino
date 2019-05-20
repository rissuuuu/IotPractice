

#include <TimerOne.h>
int encoder_pin = 2; 
unsigned int counter=0;

void setup() {
  Serial.begin(9600);
  pinMode(encoder_pin, INPUT);
  Timer1.initialize(1000000);  // set for 1 sec
  attachInterrupt(0,do_count,RISING);
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void do_count() {
  counter++;
}

void timerIsr() {
  Timer1.detachInterrupt();
  Serial.print("Motor Speed: ");
  int rotation = (counter/20)*60;
  Serial.print(rotation, DEC);
  Serial.println(" RPM");
  counter=0;
  Timer1.attachInterrupt(timerIsr);
}

