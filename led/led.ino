int led =52;
int dur[]={100,200,300,400,500};
void setup() {
pinMode(led,OUTPUT);
}

void loop() {
for(int i=0;i<5;i++){
  flash(dur[i]);
}
}
void flash(int duration){
  digitalWrite(led,HIGH);
  delay(duration);
  digitalWrite(led,LOW);
  delay(duration);
}

