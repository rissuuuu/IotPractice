int led=52;
char* letters[]={
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};
char* numbers[]={"-----", ".----", "..---", "...--", "....-", ".....", "-....",
"--...", "---..", "----."};
int dotDelay=200;

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  char ch;
  if(Serial.available())  //reading from usb
  {
    ch=Serial.read();     //reads single letter
    if(ch>='a' && ch<='z'){
      flashSequence(letters[ch - 'a']);
    }
    if(ch>='A' && ch<='Z'){
      flashSequence(letters[ch - 'A']);
    }
    if(ch>='0' && ch<='9'){
      flashSequence(numbers[ch -'0']);
    }
    else if(ch==' '){
      delay(dotDelay*4);
    }
  }
}
void flashSequence(char sequence[]){
  int i=0;
  while(sequence[i]!=NULL){
    flashDotorDash(sequence[i]);
    i++;
  }
}
void flashDotorDash(char dotorDash){
  digitalWrite(led,HIGH);
  if(dotorDash=='.'){
    delay(dotDelay);
  }
  else{
    delay(dotDelay*3);
  }
  digitalWrite(led,LOW);
  delay(dotDelay);
}


