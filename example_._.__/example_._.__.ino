char* letters[]={"._._.","_._._","__.__",".._.."};
char* numbers[]={"._.","_._"};
int led=52;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
void loop(){
char ch;
if(Serial.available()){
ch=Serial.read();
if(ch>='a' && ch<='d'){
  sequence(letters[ch-'a']);
}
else if(ch>='A' && ch<='D'){
  sequence(letters[ch-'A']);
}
else if(ch>='0' && ch<='2'){
  sequence(numbers[ch-'0']);
}
else{
  Serial.println("FUCK YOU");
}
}
}

void sequence(char chars[]){
 int i=0;
 while(chars[i]!=NULL){
  flash(chars[i]);
  i++;
 }
}

void flash(char dot){
  
  if(dot=='.'){
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    delay(100);
  }
  else{
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(100);
  }
  delay(100);
}

