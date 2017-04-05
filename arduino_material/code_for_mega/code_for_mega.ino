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


//  randomSeed(analogRead(0));
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  Serial.begin(9600);
  tft_init();
}

void loop() {
  byte * temp_array;
  temp_array = ask_temps();
  
  int n = sizeof(temp_array);
  Serial.println();
  for (int i=0;i<=n;i++)
  {
    
    tft_init();
    myGLCD.setColor(51, 204, 51);  //Greenish
    myGLCD.print("Achieving Temperature : " + String(i) + "*C", CENTER, 100);
    Serial.println(temp_array[i]);
    achieve_temp(i, temp_array[i]);
  }

  for (int i=0;i<=n;i++)
  {
    plot_iv(i);
  }
  // put your main code here, to run repeatedly:
  delay(50000);
}
