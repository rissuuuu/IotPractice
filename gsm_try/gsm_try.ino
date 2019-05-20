#include "SIM900.h"

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop(){
if(Serial1.available()){
  Serial1.write(Serial1.read());
}
if(Serial.available()){
  Serial.write(Serial.read());
}
}

