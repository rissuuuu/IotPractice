
int led[]={40,41,42,43,44,45,46,47,48};
void setup() {
for(int i=0;i<=8;i++){
  pinMode(led[i],OUTPUT);
}
}

void loop() {
for(int i=0;i<=8;i++)
{
  digitalWrite(led[i],HIGH);
  delay(10);
  digitalWrite(led[i],LOW);
}
}
