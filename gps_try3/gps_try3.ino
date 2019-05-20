#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11); // RX, TX

//Initialize the variables globally 
char GPS_text;
int comma_count = 0;
String latitude, longitude;
int South = 0, West = 0, count =1;

void setup()  
{
  Serial.begin(115200);
  mySerial.begin(57600);
}

void loop() // run over and over
{
  if (mySerial.available()){ //Check for the data available 
    GPS_text = mySerial.read(); //Store the value in the variable
    if(GPS_text == '$'){    //Check if the variable starts with '$'
      Serial.write("\n");
      comma_count = 0;
      latitude = "\0";
      longitude = "\0";
    }
    
//**************GPS Count*************//
    
    if(GPS_text == ',') //Check for the comma and separate
    {
      comma_count = comma_count +1;
    }
    if(comma_count == 2)
    {
      latitude += GPS_text;   //The receiver transmit or receive by a byte at a time. This command will be used to store the bytes in the single variable 
      count = 0;
    }
    if(comma_count == 3)
    {
      latitude += GPS_text;  
      if (count == 1)
      {
        
//  **********GPS LATITUDE DATA SEPERATION***********

        Serial.println("***************GPS DATA************");
        Serial.println("LAT:"+ latitude); //To display the GPS format latitute in ddmm.mmmm
        String dd, mm1, mm2, mm3;
        int dotlocation = latitude.indexOf('.');
        dd = latitude.substring(dotlocation-4, dotlocation-2);
        mm1 = latitude.substring(dotlocation-2, dotlocation);
        mm2 = latitude.substring(dotlocation+1, dotlocation+5);
        unsigned long D1 = dd.toInt();    //Convert the recived string to int
        unsigned long MM1 = mm1.toInt();  //Convert the recived string to int
        unsigned long MM2 = mm2.toInt();  //Convert the recived string to int
        int setdot;   //Used to set the precision
        if (D1 > 9)
          setdot = 2;  
        else 
          setdot = 1;          
        Serial.print("DD= ");  
        Serial.println(D1);    //Store the dd 
        Serial.print("mm1=");  
        Serial.println(MM1);   //Store two mm
        Serial.print("mm2=");
        Serial.println(MM2);   //Store the remain .mmmm
        Serial.print("dotlocation = ");
        Serial.println(dotlocation);
     
//***********Conversion****************//
        D1= D1 * 100000;
        Serial.println(D1);
        MM1 = MM1 * 10000;
        unsigned long temp;
        temp = MM1 + MM2;
        Serial.println(temp);
        temp = temp / 6;
        D1 = D1+ temp;   
     
        Serial.print("D1 = ");
        Serial.println(D1);
        String A = (String)D1;
        dd = A.substring(0,setdot);
        mm1= A.substring(setdot);
       
        if (GPS_text == 'S')
        {
          A = '-' + dd + '.' + mm1;  //To display the "-dd.mmmm" if its South
          Serial.write("South = \t");                   
        }
        else
        {
          A = dd + '.' + mm1;   //To display the "dd.mmmm" if its North
          Serial.write("North = \t");              
        }   
        Serial.println(A); 
       
//*********LCD Display*******// 
             
       
     }
   //to check the GPS text after comma
     count = count+1;
   }
   
   if(comma_count == 4)
   {
     longitude += GPS_text;
     count =0;
   }
   
   if(comma_count ==5)
   {
     longitude += GPS_text;
     
     if (count == 1)
     {
//  **********GPS Longitude DATA SEPERATION*********** 
       
       Serial.println("LON:"+ longitude);
       String dd, mm1, mm2, mm3;
       int dotlocation = longitude.indexOf('.');
       dd = longitude.substring(dotlocation-5, dotlocation-2);
       mm1 = longitude.substring(dotlocation-2, dotlocation);
       mm2 = longitude.substring(dotlocation+1, dotlocation+5);
       unsigned long D1 = dd.toInt();    //Convert the recived string to int
       unsigned long MM1 = mm1.toInt();  //Convert the recived string to int
       unsigned long MM2 = mm2.toInt();  //Convert the recived string to int
       int setdot;
       if (D1 > 99)
         setdot = 3;
       else if (D1 >9)
         setdot = 2;
       else
         setdot = 1;          
       Serial.print("DD= ");
       Serial.println(D1);   //Store the dd
       Serial.print("mm1=");
       Serial.println(MM1);  //Store the mm
       Serial.print("mm2=");
       Serial.println(MM2);  //Store the .mmmm
       Serial.print("dotlocation = ");
       Serial.println(dotlocation);
       
     //***********Conversion****************//
     
       D1= D1 * 100000;
       Serial.println(D1);
       MM1 = MM1 * 10000;
       unsigned long temp;
       temp = MM1 + MM2;
       Serial.println(temp);
       temp = temp / 6;
       D1 = D1+ temp;   
     
       Serial.print("D1 = ");
       Serial.println(D1);
       String A = (String)D1;
       dd = A.substring(0,setdot);
       mm1= A.substring(setdot);
       
       if (GPS_text == 'W')
       {
         A = '-' + dd + '.' + mm1;   //To display if its West
         Serial.write("West = \t");                    
       }
        else
        {
          A = dd + '.' + mm1;   //To display if its South
          Serial.write("East = \t");
        }   
        Serial.println(A); 
        
//*********LCD Display*******// 

         
       }
       count = count+1;
     }
     if(comma_count == 6)
     {
       count =0;
     }
   } 
 }
