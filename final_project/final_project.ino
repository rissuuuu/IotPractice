//Initialization of digital and analog pins attached to arduino nano...............
#include<Wire.h>

#include <DFRobot_sim808.h>
#include<String.h>
const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;


SoftwareSerial serial(10, 11);
DFRobot_SIM808 sim808(&serial);


//Sensors attached to digital pins
int vibration = 2;    //vibration sensor attached to digital pin 2;
int impact = 3;       //impact sensor attached to digital pin 3;
int trigger = 4;      //ultrasonic sensor trigger pin  attached to digital pin 4;
int echo = 5;         //ultrasonic sensor eho pin  attached to digital pin 5;
int led = 6;          //led button attached to digital pin 6;
int buzzer = 6;       //buzzer sound attached to digital pin 6;
int button = 7;       //push button attached to digital pin 7;

//Sensors attached to Analog pins
int accelo = A6;      //SCL pin of Accelerometer sensor attached to analog pin 6;
int gyro = A7;        //SDA pin of Accelerometer sensor attached to analog pin 7;
int gas_sensor = A7;  //gas smoke sensor attached to analog pin 5;

boolean clicked = false;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  serial.begin(9600);
  Serial.begin(9600);   //Starting serial communication with baud rate of 9600

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


  //All the sensors are initialized as input and output function according to their working principle
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(vibration, INPUT);
  pinMode(impact, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.println("Setup Complete");

}

void loop() {


  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 12, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  //  Serial.print("Accelerometer: ");
  //  Serial.print("X = "); Serial.print(AcX);
  //  Serial.print(" | Y = "); Serial.print(AcY);
  //  Serial.print(" | Z = "); Serial.println(AcZ);

  if (AcX <= -10000 || AcX >= 12000 || AcY <= -10000 || AcY >= 10000) {
    beep();
  }
  int impact_value = digitalRead(impact);   //reading impact sensor value

  //sending high ultrasound value in less interval and waiting for the interval to getreflected sound
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  float vals = pulseIn(echo, HIGH);
  float distance = vals / 58;
  //  Serial.println(distance);
  //  if (distance <= 50) {
  //    beep();
  //  }
  int vibration_data = digitalRead(vibration);
  //  Serial.println(vibration_data);



  int gas_sensor_data = analogRead(gas_sensor);
  //  Serial.println(gas_sensor_data);
  if (gas_sensor_data >= 100) {
    beep();
  }

  int impact_val = digitalRead(impact);
  if (impact_val == 0 && vibration_data == 1) {
    for (int i = 0; i < 5; i++) {
      beep();
    }
  }


}
void beep() {
  for (int i = 0; i <= 5; i++) {
    if (digitalRead(button) == HIGH) {
      Serial.println("clicked");
      clicked = true;
      break;
    }

    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    Serial.println("beeep beep");
  }

  if (clicked == true) {
    Serial.println("dont do anything");
    clicked = false;
  }
  else {
    call();

  }

}
void call() {
  while (1) {
    if (sim808.getGPS()) {
      double s1 = sim808.GPSdata.lat;
      double s2 = sim808.GPSdata.lon;
      Serial.print(s1);
      Serial.print(",");
      Serial.println(s2);
      Serial.println("Accident occured at following location");
      Serial.print("latitude :");
      Serial.println(sim808.GPSdata.lat);

      Serial.print("longitude :");
      Serial.println(sim808.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(sim808.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(sim808.GPSdata.heading);
      Serial.println();



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

      Serial.println("Finished all");
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(led,LOW);
      delay(50);
      //************* Turn off the GPS power ************
      break;
    }
  }
}
void toSerial()
{
  while (serial.available() != 0)
  {
    Serial.write(serial.read());
  }


}

