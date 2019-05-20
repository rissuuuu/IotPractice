#include<Servo.h>
Servo myservo;

void setup() {
myservo.attach(8);
myservo.write(0);
}

void loop() {
for(int i=0;i<=90;i++){
  myservo.write(i);
 delay(15);
}
for(int i=180;i>0;i--){
  myservo.write(i);
 delay(15);
}
}
