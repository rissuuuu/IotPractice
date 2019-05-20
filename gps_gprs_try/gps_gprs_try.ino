#include <DFRobot_sim808.h>
#include<String.h>
#include<SoftwareSerial.h>
float s1=0,s2=0;
SoftwareSerial serial(10, 11);
int butt1 = 12;
int butt2 = 22;

//Mobile phone number, need to change
#define PHONE_NUMBER  "9505984547"
DFRobot_SIM808 sim808(&serial);

void setup() {
  pinMode(butt1, INPUT);
  pinMode(butt2, INPUT);

  serial.begin(9600);
  Serial.begin(9600);
  //********Initialize sim808 module*************
  while (!sim808.init()) {
    delay(1000);
    Serial.print("Sim808 init error\r\n");
  }
  Serial.println("Sim808 init success");
  if ( sim808.attachGPS())
    Serial.println("Open the GPS power success");
  else
    Serial.println("Open the GPS power failure");
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
if (sim808.getGPS()) {
    s1 = sim808.GPSdata.lat;
    s2 = sim808.GPSdata.lon;
    serial.print(s1);
    serial.print(",");
    serial.println(s2);

    serial.print("latitude :");
    serial.println(sim808.GPSdata.lat);

    serial.print("longitude :");
    serial.println(sim808.GPSdata.lon);
    
    //************* Turn off the GPS power ************
  
  float f1=s1;
  float f2=s2;
  serial.print(f1);
    serial.print(",");
  serial.print(f2);
}




   serial.println("AT+HTTPINIT");
  delay(2000);
  toSerial();
 serial.print("AT+HTTPPARA=\"URL\",\"rissuuuu.000webhostapp.com/iot.php?data1=");
  serial.print(s1);
  serial.print(",");
  serial.print(s2);
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
  while (serial.available() != 0)
  {
    Serial.write(serial.read());
  }


}
