#include "myfiles.h"

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  Serial.begin(9600);
  
}



void loop() {
  Serial.print("@");
  plot(x,y,6);
  // put your main code here, to run repeatedly:
}
