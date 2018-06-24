#include <IRremoteESP8266.h>
#include <IRsend.h>

IRsend irsend(0);

void setup()
{
  irsend.begin();
  Serial.begin(9600);
}

void loop() {
  irsend.sendNEC(0xF4BA2988, 32);
  Serial.println("sent 0xF4BA2988");
  delay(2000);
  irsend.sendNEC(0xE0E040BF, 32);
  Serial.println("sent 0xE0E040BF");
  delay(2000);
}
