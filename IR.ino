#include <IRremote.h>


int RECV_PIN = 8;
int led = 13;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{

 Serial.begin(9600);

 irrecv.enableIRIn(); // Start the receive

 pinMode(13,OUTPUT);

}

void loop() {

  if (irrecv.decode(&results)) {

  Serial.println(results.value, HEX);

 irrecv.resume(); // Receive the next value

 }


}

 
