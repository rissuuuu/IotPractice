int cp,lp,timer=100,tuning=10;

void setup() {
pinMode(52,OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
cp=analogRead(A0);
while(abs(cp-lp)>tuning){
  digitalWrite(52,HIGH);
  delay(timer);
  lp=cp;
  cp=analogRead(A0);
}
digitalWrite(52,LOW);
}
