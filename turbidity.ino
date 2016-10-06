int photocellPin = A1;    //connect cell to analog pin 0 with 10k pull down resistor to ground
int ledPin = 13;  //Connect LED to run pin 13 in series with appropriate resistor

void setup() {
  Serial.begin(9600);  //Begin serial connection between Arduino and PC
  pinMode (ledPin, OUTPUT);  //Set pin to outut
 pinMode (photocellPin, INPUT);

}

void loop() {
 Serial.print("Cell = "); 
 Serial.println(analogRead(photocellPin));  //print analog read to serial monitor on PC

float val = analogRead(photocellPin);  //create variable to take in analog reading from cell
Serial.print("val ");
Serial.println(val);
digitalWrite(13, HIGH);
float ardval = val*0.00488758553;  //arduino value units 
Serial.print("ardval ");
Serial.println(ardval);
float r1 = (50000/ardval)-10000; //R1 value when using Ohm's law
Serial.print("r1 ");
Serial.println(r1);
float I = ardval/r1; //value of I which we are solving for
float NTUval = I*70000;  //200 = units in NTU
delay(1000);

delay(1000);

delay(1000);
Serial.print("I ");
Serial.println(I);
delay(1000);
Serial.print("NTUval ");
Serial.println(NTUval);
delay(1000);



}
