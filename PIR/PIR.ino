int led=36;
int pir=2;
boolean val=true;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
}

void loop() {
int readval=digitalRead(pir);
if(readval==HIGH){
  long int a=millis();
  double b=a/1000;
  Serial.print("Motion detected at");
  Serial.print("\t");
  Serial.println(b);
}
if(readval==LOW)
{
  Serial.println("Motion ended");
}

}
