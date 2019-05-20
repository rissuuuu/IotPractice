int led=5;
int led2=7;
int pot=A0;
int sensorvalue=0;
int outputvalue=0;
int outputvalue2;
void setup() {
Serial.begin(9600);
}

void loop() {
sensorvalue=analogRead(pot);
outputvalue=map(sensorvalue,0,1023,0,255);
outputvalue2=map(sensorvalue,0,1023,255,0);
analogWrite(led,outputvalue);
analogWrite(led2,outputvalue2);
Serial.print("sensor=");
Serial.print(sensorvalue);
Serial.print("\t Red_LED=");
Serial.print(outputvalue);
Serial.print("\tsensor=");
Serial.print(sensorvalue);
Serial.print("\t BLUE_LED=");
Serial.println(outputvalue2);
delay(2);
} 
