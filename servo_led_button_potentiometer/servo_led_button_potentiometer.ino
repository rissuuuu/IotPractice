#include<Servo.h>
Servo servo;
int butt[]={ 33,39,47,53};
int led[]={30,36,42,50};
int serv=28;
int pot=A0;
int pots=0;
int maps=0;
int mappd=0;

void setup() {
  for(int i=0;i<5;i++){
    pinMode(led[i],OUTPUT);
    pinMode(butt[i],INPUT);
  }
  servo.attach(serv);
  Serial.begin(9600);
  

}

void loop() {
  
  int flag=0; 
  pots=analogRead(pot);
  maps=map(pots,0,1023,0,180);
  mappd=map(pots,0,1023,0,255);
  
    analogWrite(led[0],mappd);
    analogWrite(led[1],mappd);
    analogWrite(led[2],mappd);
    analogWrite(led[3],mappd);




  servo.write(maps);
  Serial.println(maps);
    Serial.println(mappd);


}
