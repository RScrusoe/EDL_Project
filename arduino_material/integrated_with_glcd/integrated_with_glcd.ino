#include "myfiles.h"
#include "hardware.h"
void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  Serial.begin(9600);
  tft_init();
}



void loop() {
  tft_init();
  ask_temps();
  delay(3000);
  tft_init();
  plot_iv(x,y,82);
  //tft_init();
  delay(50000);
  // put your main code here, to run repeatedly:
}
