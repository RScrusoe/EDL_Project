#include "myfuncs.h"
#include "myvars.h"
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
  int n = ask_temps();
  Serial.println("size = " + String(n));
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
  
  for (int i=0;i<n;i++)
  {
    plot_iv(i);
  }

  while(1){}

}
