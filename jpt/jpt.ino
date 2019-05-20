#include<String.h>
void setup() {
Serial.begin(9600);
}

void loop() {
float a=10.12;
float b=11.34;

float s1=float.parseFloat(a);
String s2=s1;
Serial.println(s2);
}
