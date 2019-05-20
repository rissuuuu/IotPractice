#include <DFRobot_sim808.h>
#include<String.h>

float f1 = 0, f2 = 0;
//Mobile phone number, need to change
#define PHONE_NUMBER  "9505984547"
SoftwareSerial mySerial(10, 11);
DFRobot_SIM808 sim808(&mySerial);

void setup() {

  mySerial.begin(9600);
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

}
void loop() {
  if (sim808.getGPS()) {
    f1 = sim808.GPSdata.lat;
    f2 = sim808.GPSdata.lon;


    /*Serial.print("latitude :");
      Serial.println(sim808.GPSdata.lat);

      Serial.print("longitude :");
      Serial.println(sim808.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(sim808.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(sim808.GPSdata.heading);
      Serial.println();

      //************* Turn off the GPS power ************
    */





    Serial.print(f1);
    Serial.print(",");
    Serial.println(f2);
      
  }
       Serial.print(f1);
    Serial.print(",");
    Serial.println(f2);

}
