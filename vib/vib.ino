int vib=A0;
int buzzer=8;
void setup() {
pinMode(vib,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
int aa=analogRead(vib);
Serial.println(aa);
if(aa>=500){
  for(int i=0;i<5;i++){
  
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
}
}
