#include<VirtualWire.h>


const int motorpinl1  = 6;  // Pin 14 of L293
const int motorpinl2  = 7;  // Pin 10 of L293
//Motor B
const int motorpinr1  = 8; // Pin  7 of L293
const int motorpinr2  = 9;  // Pin  2 of L293



void setup() {
    pinMode(motorpinl1, OUTPUT);
    pinMode(motorpinl2, OUTPUT);
    pinMode(motorpinr1, OUTPUT);
    pinMode(motorpinr2, OUTPUT);
    
vw_set_ptt_inverted(true);
vw_set_rx_pin(12);
vw_setup(4000);
vw_rx_start();
}

void loop() {
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen=VW_MAX_MESSAGE_LEN;
if(vw_get_message(buf,&buflen)){
  if(buf[0]=='L'){
      /*digitalWrite(motorpinl1,HIGH);
      digitalWrite(motorpinr2,HIGH);  
      digitalWrite(motorpinl2,LOW);
      digitalWrite(motorpinr1,LOW);*/
  }
  if(buf[0]=='R'){
    digitalWrite(motorpinr1,LOW);
    digitalWrite(motorpinl2,LOW);
    
    digitalWrite(motorpinr2,LOW);
    digitalWrite(motorpinl1,LOW);
  }
  if(buf[0]=='F'){
    digitalWrite(motorpinl1,HIGH);
    digitalWrite(motorpinr1,HIGH);
    
    digitalWrite(motorpinr2,LOW);
    digitalWrite(motorpinl2,LOW);
  }
  if(buf[0]=='D'){
    digitalWrite(motorpinl1,LOW);
    digitalWrite(motorpinl2,HIGH);
    digitalWrite(motorpinr1,LOW);
    digitalWrite(motorpinr2,HIGH);
  }
  if(buf[0]=='M'){
      digitalWrite(motorpinl1,HIGH);
      digitalWrite(motorpinr2,HIGH);  
      digitalWrite(motorpinl2,LOW);
      digitalWrite(motorpinr1,LOW);
  }
  if(buf[0]=='N'){
      digitalWrite(motorpinl1,LOW);
      digitalWrite(motorpinr2,LOW);  
      digitalWrite(motorpinl2,HIGH);
      digitalWrite(motorpinr1,HIGH);
  }
  if(buf[0]=='S'){
    digitalWrite(motorpinr1,LOW);
    digitalWrite(motorpinl2,LOW);
    
    digitalWrite(motorpinr2,LOW);
    digitalWrite(motorpinl1,LOW);
  }
  
  }
}



