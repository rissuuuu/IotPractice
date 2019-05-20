int led1=5;
int led2=7;
int pot=A0;
void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}

void loop() {
int sensorval=analogRead(A0);
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
delay(sensorval);
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
delay(sensorval);
}
