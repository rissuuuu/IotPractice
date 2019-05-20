int matrix[9]={
  40,41,42,
  43,44,45,
  46,47,48
};
void setup() {
for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
    pinMode(matrix[i],OUTPUT);
  }
}
}

void loop() {
  int i;
for(i=0;i<9;i++){
 

  if(i%2==0){
  digitalWrite(matrix[i],HIGH);
  }
 
  


} delay(500);

  digitalWrite(matrix[i],LOW);
}
