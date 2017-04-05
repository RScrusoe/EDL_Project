#include "myfuncs.h"
#include "myvars.h"

void setup() {
    pinMode(relay_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(diode_pin, INPUT);
  pinMode(current_read_pin, INPUT);
  pinMode(lm35_5volt_pin, OUTPUT);
  analogWrite(lm35_5volt_pin,255);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
