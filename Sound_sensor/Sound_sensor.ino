int led=2;
int sound=A0;
const int limit=50;
void setup() {
  Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(sound,INPUT);
}
void loop() {
int soundval=analogRead(sound);
if(soundval>limit){
  digitalWrite(led,HIGH);
  delay(1000);
}
else{
  digitalWrite(led,LOW);
}
}
