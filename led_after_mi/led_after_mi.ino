int led=5;

int butt=13;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(13,INPUT);
}

void loop() {
  // put your main code here, to run repea tedly:
int count=0;
int reads=digitalRead(butt);
switch(reads){


case 1:
      digitalWrite(led,HIGH);
      count++;
    break;
}
Serial.print(reads);
Serial.print("\t");
Serial.println(count);
}
