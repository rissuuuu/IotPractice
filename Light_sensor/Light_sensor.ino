int led=7;
int ls=A7;
void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
int val=analogRead(ls);
if(val==1023){
  digitalWrite(led,LOW);
}
else{
digitalWrite(led,HIGH);
}
Serial.println(val);
delay(100);
}
