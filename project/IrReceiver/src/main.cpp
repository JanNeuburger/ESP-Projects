#include <IRremote.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 9, 2);

int receiverpin = 02;

IRrecv irrecv(receiverpin);
decode_results results;


void setup() {
  lcd.begin(16, 2);
  pinMode(receiverpin, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    lcd.clear();
    lcd.print(results.value, HEX);
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