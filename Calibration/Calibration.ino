
const int sensorpin=A0;
const int ledpin=5;

int sensorval=0;
int sensorMin=1023;
int sensorMax=0;


void setup() {
pinMode(13,OUTPUT);
digitalWrite(13,HIGH);
while(millis()<5000){
  sensorval=analogRead(sensorpin);
  if(sensorval>sensorMax){
    sensorMax=sensorval;
  }
  if(sensorval<sensorMin){
    sensorMin=sensorval;
  }
}
digitalWrite(13,LOW);
}

void loop() {
 sensorval=analogRead(sensorpin);
 sensorval=map(sensorval,sensorMin,sensorMax,0,255);
 sensorval=constrain(sensorval,0,255);
 analogWrite(ledpin,sensorval);
}
