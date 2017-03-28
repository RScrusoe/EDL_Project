#include "myfiles.h"

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  
  
}



void loop() {
  plot(x,y,6);
  // put your main code here, to run repeatedly:


}
