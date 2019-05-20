#include<SoftwareSerial.h>
SoftwareSerial serial(10,11);


void setup() {
serial.begin(9600);
Serial.begin(9600);
Serial.println("Config SIM808...");
delay(2000);
Serial.println("Done!...");
serial.flush();
Serial.flush();

serial.println("AT+CGATT?");
delay(100);
toSerial();

  serial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
  serial.println("AT+SAPBR=3,1,\"APN\",\"taif\"");
  delay(2000);
  toSerial();

  // bearer settings
  serial.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();
}

void loop() {
  
    Http();
 
}
void Http(){
  serial.println("AT+HTTPINIT");
  delay(2000);
  toSerial();
  float a=10.10;
  float b=20.20;
  serial.print("AT+HTTPPARA=\"URL\",\"rissuuuu.000webhostapp.com/iot.php?data1=");
  serial.print(a);
  serial.print(",");
  serial.print(b);
  serial.print( "\"\r\n");
  serial.print("AT+HTTPPARA=\"CID\",1\r\n");
  delay(2000);
   toSerial();

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   serial.println("AT+HTTPACTION=1");
   delay(6000);
   toSerial();

   // read server response
   serial.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   serial.println("");
   serial.println("AT+HTTPTERM");
   toSerial();
   delay(300);

   serial.println("");
   delay(10000);
}

void toSerial()
{
  while(serial.available()!=0)
  {
    Serial.write(serial.read());
  }


}
