int led=36;
int digital=2;
int analog=A0;
int temp=A1;
int impact=32;
int trigger=42;
int echo=40;
int sensorThres=200;
void setup() {
Serial.begin(9600);
pinMode(analog,INPUT);
pinMode(digital,INPUT);
pinMode(led,OUTPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(impact,INPUT);
}

void loop() {
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger,LOW);
  float vals=pulseIn(echo,HIGH);
  float distance=vals/58;
   if(distance<=10){
    Buzz();
   }

/*int val=analogRead(analog);
Temp();



 if(val>=sensorThres){
  Buzz();
 }
 else{
  digitalWrite(led,LOW);
 }
 */
int impactval=digitalRead(impact);
if(impactval==0){
    Buzz();
    }
else{
  digitalWrite(led,LOW);
}
}
void Buzz(){
  for(int i=0;i<5;i++){
  digitalWrite(led,HIGH);
  delay(300);
  digitalWrite(led,LOW);
  delay(300);
  }
}
void Temp(){
  int tempval=analogRead(temp);
float fintemp=tempval*0.488758553;
Serial.print("Temp->");
Serial.println(fintemp);
delayMicroseconds(10);
}


