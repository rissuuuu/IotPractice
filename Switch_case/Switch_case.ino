 

void setup() {
  Serial.begin(9600);
for(int i=44;i<=52;i++){
  pinMode(i,OUTPUT);
}
}

void loop() {
if(Serial.available()>0){
  int in=Serial.read();
  switch(in){
    case 'a':digitalWrite(44,HIGH);break;
    case 'b':digitalWrite(46,HIGH);break;
    case 'c':digitalWrite(48,HIGH);break;
    case 'd':digitalWrite(50,HIGH);break;
    case 'e':digitalWrite(52,HIGH);break;
    default:
    for(int i=44;i<=52;i++){
      digitalWrite(i,LOW);
      delay(500);
    }

  }
}
}
