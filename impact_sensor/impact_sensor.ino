int impact= 32;
void setup() {
pinMode(impact,INPUT);
Serial.begin(9600);
}

void loop() {
int rate=digitalRead(impact);
int flag=0;
if(rate){
  flag=1;
}
if(flag==1){
  Serial.println("A");
}
}
