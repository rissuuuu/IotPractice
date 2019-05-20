int bt=30;
int count=0;
void setup() {
pinMode(bt,INPUT);
Serial.begin(9600);
}

void loop() {
int a=digitalRead(bt);
if(a==HIGH&&count%2==0){
  Serial.println("A");
count++;
}
else if(a==HIGH && count%2==1){
  Serial.println("A");
  
}


}
