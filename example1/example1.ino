char* take[]={"1","2","3","4"};
int led=44;

void setup() {
Serial.begin(9600);

pinMode(led,INPUT);

}

void loop() {
  

digitalWrite(led,HIGH);


}
