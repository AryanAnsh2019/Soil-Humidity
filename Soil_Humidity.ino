#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " Sg8woTomFTKI2mzGuznfPLFpIgbRemtC";

//// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ktayal";
char pass[] = "1357924680";
int i;
int sensorPin = 36;   // Input pin for the Flame Sensor
int sensorValue = 0;  // Variable to store the value coming from the flame sensor
int leds[4]={15,4,5,18};
void setup()
{
  // Debug console
  Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
  pinMode(sensorPin, INPUT);
  for(i=0;i<=3;i++)
  {
   pinMode(leds[i],OUTPUT); 
  }
}

void loop()
{
  Blynk.run();
  sensorValue = analogRead(sensorPin);
//  Serial.print(sensorValue);
  if (sensorValue>4000) 
  {
    for(i=0;i<=3;i++)
    {
      digitalWrite(leds[i],LOW); 
    }
    Blynk.notify("I need a lot of water..");
    digitalWrite(15,HIGH);
  }
  else if(sensorValue>=1500&&sensorValue<=4000)
  {   
    for(i=0;i<=3;i++)
    {
      digitalWrite(leds[i],LOW); 
    }
    Blynk.notify("Give me some water....");
    digitalWrite(4,HIGH);
  }
  else if (sensorValue>=800&&sensorValue<1500)
  {
    for(i=0;i<=3;i++)
    {
      digitalWrite(leds[i],LOW); 
    }
    digitalWrite(18,HIGH);
  }
  else
  {  
    for(i=0;i<=3;i++)
    {
      digitalWrite(leds[i],LOW); 
    }
    Blynk.notify("Too much water.....");
    digitalWrite(5,HIGH);
  }
    //SensorValue,550,0,0,100);
//
//   Serial.print("Mositure : ");
//
  //Serial.print(sensorValue);
//
  //Serial.println("%");
  
   delay(1000);
}
