//photocell sensor pin = analogInPin A2
//led pin = digitalPin 13

//ph sensor pin = analogInPin A0
//ph analogOutPin = digitalPin 9




#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 2

int analogInPin = A1;
int analogOutPin   = 9;
int sensorValue = 0;
int outputValue = 0;

int photocellPin = A2;
int ledPin = 13;



OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensor(&oneWire);





void setup(void)
{
    Serial.begin(9600);

    pinMode(analogInPin,INPUT);
    pinMode(analogOutPin,OUTPUT);

    pinMode(ledPin,OUTPUT);
    pinMode(photocellPin,INPUT);
    
    sensor.begin();


}

void loop(void)
{
//Temperature
  Serial.print(" Requesting temperatures...");
  sensor.requestTemperatures(); 
  Serial.println("DONE");
  Serial.print("Temperature : ");
  Serial.print(sensor.getTempCByIndex(0));
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0,1023,0,5000);
  analogWrite(analogOutPin,outputValue);
//Ph sensor
  Serial.print("ph value from sensor =");
  Serial.print(sensorValue);
  Serial.print("\t output = ");      
  Serial.println(analogRead(1)* 5.00 / 1024, 2);   
  Serial.print(analogRead(1)); 

//photocell Sensor
  Serial.print("Cell = ");
  Serial.println(analogRead(photocellPin));
  float val = analogRead(photocellPin);  
  Serial.print("val ");
  Serial.println(val);
  digitalWrite(13, HIGH);
  float ardval = val*0.00488758553; 
  Serial.print("ardval ");
  Serial.println(ardval);
  float r1 = (50000/ardval)-10000; 
  Serial.print("r1 ");
  Serial.println(r1);
  float I = ardval/r1; 
  float NTUval = I*70000;  
  delay(1000);
  Serial.print("I ");
  Serial.println(I);
  delay(1000);
  Serial.print("NTUval ");
  Serial.println(NTUval);

  
  delay(3000);



}