#include<Keypad.h>
 String keys="";
const byte ROWS=4;  //four rows
const byte COLS=4;  //four columns
int led=2;
//define symbols on the button of the keypads
char hexakeys[ROWS][COLS]={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
  };
byte rowPins[ROWS]={22,30,38,46}; //row pins of the keypad
byte colPins[COLS]={27,35,43,51}; //col pins of the keypad

Keypad keypads=Keypad(makeKeymap(hexakeys),rowPins,colPins,ROWS,COLS);
void setup() {
  pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
char customKey=keypads.getKey();
  if(customKey){
  Serial.println(customKey);
  store(customKey);
}

}
void store(char customKey){
keys+=customKey;
  if(keys){
    if(customKey=='A'){
      keys="";
      digitalWrite(led,LOW);
    }
  Serial.println(keys);
  key(keys);
  }
  
  }
void key(String keyss){
  if(keyss=="12345"){
    digitalWrite(led,HIGH);
  }
}

