#include <DFRobot_sim808.h>
int butt1=22;
int butt2=22;

  //Mobile phone number, need to change
  #define PHONE_NUMBER  "9505984547"   
SoftwareSerial mySerial(10,11);
  DFRobot_SIM808 sim808(&mySerial);

  void setup() {
    pinMode(butt1,INPUT);
        pinMode(butt2,INPUT);

    mySerial.begin(9600);
    Serial.begin(9600);
    //********Initialize sim808 module*************
    while(!sim808.init()) {
        delay(1000);
        Serial.print("Sim808 init error\r\n");
    }
    Serial.println("Sim808 init success");
    if( sim808.attachGPS())
        Serial.println("Open the GPS power success");
    else
        Serial.println("Open the GPS power failure");
    
  }
  void loop() {

    if(digitalRead(butt1)){
  /*Serial.println("Start to call ...");

    //*********Call specified number***************
    sim808.callUp(PHONE_NUMBER);
    Serial.println("Call Ended");
  
  
  
}

    if(digitalRead(butt2)==HIGH){*/
    
        if (sim808.getGPS()) {
      Serial.print(sim808.GPSdata.year);
      Serial.print("/");
      Serial.print(sim808.GPSdata.month);
      Serial.print("/");
      Serial.print(sim808.GPSdata.day);
      Serial.print(" ");
      Serial.print(sim808.GPSdata.hour);
      Serial.print(":");
      Serial.print(sim808.GPSdata.minute);
      Serial.print(":");
      Serial.print(sim808.GPSdata.second);
      Serial.print(":");
      Serial.println(sim808.GPSdata.centisecond);
      Serial.print("latitude :");
      Serial.println(sim808.GPSdata.lat);
      Serial.print("longitude :");
      Serial.println(sim808.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(sim808.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(sim808.GPSdata.heading);
      Serial.println();

      //************* Turn off the GPS power ************
    }
  }
  
  


  }
