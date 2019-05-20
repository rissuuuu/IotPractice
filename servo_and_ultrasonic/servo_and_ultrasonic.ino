#include<Servo.h>
Servo servo;
int servo_pos=0;
int myservo=9;
int trigger=52;
int echo=53;
int pulseWidth;
//int pot=A0;
long duration;
int distance;
void setup() {
servo.attach(9);
//pinMode(pot,INPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
/*int pot_val=analogRead(pot);
pulseWidth=map(pot_val,0,1023,500,2400);
digitalWrite(myservo,HIGH);
delayMicroseconds(pulseWidth);
digitalWrite(myservo,LOW);
delayMicroseconds(20000-pulseWidth);
delay(80);*/
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(2);
duration=pulseIn(echo,HIGH);
distance=duration*0.034/2;
Serial.print("Distance:");
Serial.print(distance);
Serial.print("\t Duration");
Serial.println(duration);


if(distance<=10){
 servo_pos=0;
 servo.write(servo_pos);
 servo_pos++;
 }
 if(distance>10){
  servo_pos=89;
 servo.write(servo_pos);
 servo_pos--;
}



}
