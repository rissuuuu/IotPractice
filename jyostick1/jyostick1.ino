int up=3;
int down=5;
int left=6;
int right=4;
int roundbutt=2;
int x_axis=A0;
int y_axis=A1;
int a1=7;
int a2=8;
int a3=9;
int a4=10;
void setup() {
pinMode(x_axis,INPUT);
pinMode(y_axis,INPUT);
pinMode(a1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(a3,OUTPUT);
pinMode(a4,OUTPUT);


Serial.begin(9600);
}

void loop() {
int val1=analogRead(x_axis);
int val2=analogRead(y_axis);
Serial.print(val1);
Serial.print("\t");
Serial.println(val2);
if(val2<400){
forward();
}
else if(val2>800){
backward();


}
else{
  
digitalWrite(a1,LOW);
digitalWrite(a2,LOW);
digitalWrite(a3,LOW);
digitalWrite(a4,LOW);
}}

void forward(){
digitalWrite(a1,HIGH);
digitalWrite(a2,LOW);
digitalWrite(a3,HIGH);
digitalWrite(a4,LOW);
}

void backward(){
digitalWrite(a1,LOW);
digitalWrite(a2,HIGH);
digitalWrite(a3,LOW);
digitalWrite(a4,HIGH);
  
}


