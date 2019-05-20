int led=52;
void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
char ch;
if(Serial.available()){
  ch=Serial.read();
  if(ch=='a'){
    digitalWrite(led,HIGH);
  }
  if(ch=='b'){    digitalWrite(led,LOW);
  }
}
}
