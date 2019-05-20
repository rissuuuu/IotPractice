void setup() {
Serial.begin(9600);
}

void loop() {
int a=random(1,10);
Serial.println(a);
delay(1000);
}
