int temp=0;


void setup() {
Serial.begin(9600);
pinMode(temp,INPUT);
}

void loop() {
int data=analogRead(temp);
float val=data*0.488758553;
Serial.println(val);
delay(100);
}
