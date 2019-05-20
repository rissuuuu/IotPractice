int trigger=9;
int echo=8;
int buzzer=7;
void setup() {
  Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
digitalWrite(trigger,LOW);
delayMicroseconds(50);
digitalWrite(trigger,HIGH);
delayMicroseconds(50);
digitalWrite(trigger,LOW);
delayMicroseconds(50);

int data=pulseIn(echo,HIGH);
Serial.println(data);
if(data<=1000){
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(200);
}
}
