int trigger=3;
int echo=2;
int led=4;
void setup() {  
Serial.begin(9600);
pinMode(echo,INPUT);
pinMode(trigger,OUTPUT);
pinMode(led,OUTPUT);
}
void loop() {
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
float distance=pulseIn(echo,HIGH);
distance=distance/58;
Serial.println(distance);
if(distance<=15){
  digitalWrite(led,HIGH);
}
else{
  digitalWrite(led,LOW);
}
}
