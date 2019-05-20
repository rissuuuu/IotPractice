int tempsensor=48;
int led=52;
int buzzer=50;
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
int readsensor=analogRead(tempsensor);
float voltage=readsensor*5;
voltage/=1024.0;
Serial.print(voltage);
Serial.println("volts");

float temperatureC=(voltage-0.5)*100;
Serial.print(temperatureC);
Serial.println("degree C");

float temperatureF=(temperatureC*9.0/5.0)+32.0;
Serial.print(temperatureF);
Serial.println("degrees F");

if(temperatureC<30&&temperatureC>25){
  digitalWrite(led,LOW);
  digitalWrite(buzzer,HIGH);
}
else if(temperatureC<25){
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
}
else if(temperatureC>30){
digitalWrite(buzzer,HIGH);
delay(5000);
}

}
