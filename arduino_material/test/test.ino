#include "my.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
}

void loop() {
  digitalWrite(ledpin,HIGH);
  delay(1000);
    digitalWrite(ledpin,LOW);
    delay(1000);
  // put your main code here, to run repeatedly:

}
