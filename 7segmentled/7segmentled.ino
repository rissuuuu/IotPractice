int led[]={26,31,34,37,40,45,48,53};
  
void setup() {
  for(int i=0;i<8;i++)
    {
      pinMode(led[i],OUTPUT);
    }
  }

void loop() {
  for(int i=0;i<8;i++)
    {
      digitalWrite(led[i],HIGH);
      delay(1000);
    }
  for(int i=0;i<8;i++)
    {
      digitalWrite(led[i],LOW);
      delay(1000);
    }
}
