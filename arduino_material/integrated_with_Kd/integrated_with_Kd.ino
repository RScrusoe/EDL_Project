#include "myvars.h"

void setup()
{
  pinMode(relay_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(diode_pin, INPUT);
  pinMode(current_read_pin, INPUT);
  pinMode(lm35_5volt_pin, OUTPUT);
  analogWrite(lm35_5volt_pin,255);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  ask_temps();
  Serial.print("Enter input Temperature using keypad:: ");
  temp_setpoint = get_input_temp();
  Serial.println(temp_setpoint);
  achieve_temp(temp_setpoint);  
  



  while (1) {}
  
}


