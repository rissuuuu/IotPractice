#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

void setup()
{
mySerial.begin(19200);               // the GPRS baud rate   
delay(2000);
mySerial.println("AT");
if(Serial.available()!=0)
{mySerial.print(Serial.read());

}mySerial.println("ATD9505984547;"); // xxxxxxxxx is the number you want to dial.  




delay(10000); 
delay(10000); 

mySerial.println("ATH"); //End the call.
if(mySerial.available()!=0)

mySerial.print(mySerial.read());
}


void loop()
{
//Do nothing
}
