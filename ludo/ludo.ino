int led[]={32,33,36,40,45,49};
int pushbt=50;
int stops=30;
void setup() {
for (int i = 0; i < 6; i++)
{
  Serial.begin(9600);
pinMode(led[i], OUTPUT);
digitalWrite(led[i],LOW);
}
pinMode(pushbt,INPUT);
pinMode(stops,INPUT);

}

void loop() {
   if(digitalRead(stops)){
  for(int i=0;i<6;i++){
    digitalWrite(led[i],LOW);
  }
  }
 if(digitalRead(pushbt)){
  for(int i=0;i<6;i++){
    digitalWrite(led[i],LOW);
  }
  randoms();
}
  
}

void randoms(){
  int a=random(0,6);
  int lengths=random(15,25);
  shows(lengths);
  displays(a);
}

void shows(int lengths){
  for(int i=0;i<lengths;i++){
    for(int j=0;j<6;j++){
    digitalWrite(led[j],HIGH);
    delay(5);
    digitalWrite(led[j],LOW);
    delay(5);
  }
  }
 
}

void displays(int a){
  switch(a){
    case 0:
    for(int i=0;i<1;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
    case 1:for(int i=0;i<2;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
    case 2:for(int i=0;i<3;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
    case 3:for(int i=0;i<4;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
    case 4:for(int i=0;i<5;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
    case 5:for(int i=0;i<6;i++){
    digitalWrite(led[i],HIGH);
    delay(5);}
    break;
  }  }

