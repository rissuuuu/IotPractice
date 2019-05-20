int t=50;
int arr[]={44,46,48,50,52};
void setup() {
for(int i=0;i<=5;i++)
{
  pinMode(arr[i],OUTPUT);
}
}

void loop() {
for(int i=0;i<=5;i++){
  digitalWrite(arr[i],HIGH);
  delay(t);
  digitalWrite(arr[i],LOW);
}
for(int i=5;i>=0;i--){
  digitalWrite(arr[i],HIGH);
  delay(t);
  digitalWrite(arr[i],LOW);
}
}
