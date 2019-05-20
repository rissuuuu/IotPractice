#include<SoftwareSerial.h>
#include<String.h>
char phone_no[]="9505984547";
SoftwareSerial serial(0,1);
int buttcall=30;
int buttcut=40;
int impact=32;
int gas=A0;
int beeped=50;
int calling=0;
boolean clicked=false;

void setup(){
    pinMode(buttcall,INPUT);
    pinMode(buttcut,INPUT);
    pinMode(impact,INPUT);
    pinMode(beeped,OUTPUT);
    pinMode(gas,INPUT);
    serial.begin(9600);  
   


}
void loop(){
  int value=analogRead(gas);
  if(value>=100){
    beep();
    
  }

  if(digitalRead(buttcall)==HIGH){ 
    GPSS();
  delay(1000);
  }
  
  if(digitalRead(buttcut)==HIGH){  
  serial.println("ATH"); 
  serial.println("Call Hanged");
  digitalWrite(beeped,LOW);
    delay(1000);
  }
  
  if(digitalRead(impact)==LOW){
    serial.println("Accident detected");
    calling=1;
  }
  if(calling==1){
    beep();
    calling=0;
  }
  

}
 void beep(){
    for(int i=0;i<20;i++){
     
    digitalWrite(beeped,HIGH);
    delay(100);
    digitalWrite(beeped,LOW);
    delay(100);
    
    if(digitalRead(buttcut)==HIGH){
      digitalWrite(beep,LOW);   
       clicked=true;
       break;
          }
          
}
  if(!clicked){
    call();
  }
  clicked=false;
}
void call(){
  serial.print("Calling"); 
  serial.println("AT");
  serial.print("ATD");
  serial.print(phone_no);
  serial.println(";");
  
}
void GPSS(){


  
}

void cuts(){
  digitalWrite(beep,LOW);   
  serial.println("ATH");
  serial.println("call Terminated");
  delay(500);
  loop();
}
  



