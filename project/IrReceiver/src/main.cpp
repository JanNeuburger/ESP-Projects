#include <Arduino.h>
#include <IRremote.h>
 

int receiverpin = 2;

IRrecv irrecv(receiverpin);
decode_results results;


void setup() {
  pinMode(receiverpin, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(150);
  }
}

//#include <IRremote.h>

//IRsend irsend;

//void setup() {
//  Serial.begin(9600);
//}

//void loop() {
//  delay(10000);
//  irsend.sendNEC(..., 32); //Power Code
//  Serial.println("Power");
//  delay(10000);
//}