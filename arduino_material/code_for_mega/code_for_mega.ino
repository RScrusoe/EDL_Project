#include "myfuncs.h"    //This file contains all the necessary methods (functions)
#include "myvars.h"     //This file contains all the varibles with their initializations
#include "AH_MCP4921.h"
void setup() {
  AnalogOutput.setValue(0);
  pinMode(relay_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(diode_pin, INPUT);
  pinMode(current_read_pin, INPUT);
  pinMode(lm35_5volt_pin, OUTPUT);
  analogWrite(lm35_5volt_pin,255);
//  SPI.begin(); // wake up the SPI bus.
//  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
  // put your setup code here, to run once:


//  randomSeed(analogRead(0));
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  Serial.begin(9600);
  tft_init();
}

void loop() {
  
//STEP-1
//Ask number of Temperatures
//And take all the temperature inputs
  int n = ask_temps();
  Serial.println("size = " + String(n));
//STEP-2
//Achieve the temperature and store corresponding IV characteristic data in particular multi dimensional array
  for(int i = 0;i<n;i++){Serial.println(temp_array[i]);}
  Serial.println("@@@");
  for (int i=0;i<n;i++)
  {   
    tft_init();
    myGLCD.setColor(51, 204, 51);  //Greenish
    myGLCD.print("Achieving Temperature : " + String(temp_array[i]) + "*C", CENTER, 100);
    delay(3000);
    tft_init();
    plot_temp_axis();
    Serial.println(temp_array[i]);
    achieve_temp(i, temp_array[i]);
  }
  tft_init();
  plot_iv_axis();
//STEP-3
//Plot iv characteristics according to the data stored in the multi-dimensional array
  for (int i=0;i<n;i++)
  {
    plot_iv(i);
  }

  //The end
  //Stay here forever
  while(1){}

}
