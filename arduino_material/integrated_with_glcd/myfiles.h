#pragma once
#include <UTFT.h>
#include "hardware.h" 
// Declare which fonts we will be using
extern uint8_t SmallFont[];
 
// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Arduino Uno / 2009:
// -------------------
// Standard Arduino Uno/2009 shield            : <display model>,A5,A4,A3,A2
// DisplayModule Arduino Uno TFT shield        : <display model>,A5,A4,A3,A2
//
// Arduino Mega:
// -------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Mega      : <display model>,38,39,40,41
//
// Remember to change the model parameter to suit your display module!
UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
//UTFT myGLCD(ILI9325D_8,38,39,40,41);
int start_pix_x = 15;
int start_pix_y = 15;
float x[82] = {0,0.05,0.11,0.17,0.23,0.29,0.35,0.4,0.44,0.47,0.49,0.51,0.53,0.54,0.55,0.56,0.57,0.57,0.58,0.59,0.59,0.59,0.6,0.6,0.61,0.61,0.61,0.62,0.62,0.62,0.63,0.63,0.63,0.63,0.63,0.63,0.64,0.64,0.64,0.64,0.65,0.65,0.65,0.65,0.65,0.66,0.66,0.66,0.66,0.66,0.66,0.66,0.67,0.67,0.67,0.67,0.67,0.67,0.67,0.68,0.68,0.68,0.68,0.68,0.68,0.68,0.68,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69};
float y[82] = {0,0.01,0.01,0.02,0.01,0.01,0.02,0.03,0.05,0.08,0.12,0.16,0.21,0.26,0.3,0.36,0.41,0.47,0.52,0.57,0.63,0.69,0.75,0.8,0.86,0.92,0.98,1.03,1.09,1.15,1.21,1.26,1.32,1.38,1.44,1.5,1.56,1.62,1.68,1.74,1.79,1.85,1.91,1.97,2.03,2.09,2.15,2.21,2.27,2.33,2.39,2.45,2.5,2.57,2.63,2.68,2.74,2.81,2.87,2.92,2.98,3.04,3.11,3.16,3.22,3.28,3.34,3.4,3.46,3.52,3.58,3.65,3.71,3.77,3.83,3.89,3.95,4.01,4.07,4.13,4.19,4.26};


float prevx,prevy = 0;
 
 
float minNum(float *z, int zsize);
float maxNum(float *z, int zsize);
 
void tft_init()
{
  myGLCD.clrScr();
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 319, 13);
  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0, 226, 319, 239);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("* PELTIER TEMPERATURE SETTABLE PLATFORM*", CENTER, 1);
  myGLCD.setBackColor(64, 64, 64);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print("YASHASWI  |  RAHUL  | UDAY", CENTER, 227);
 
  myGLCD.setColor(0, 0, 255);
  //myGLCD.drawRect(0, 14, 319, 225);
 
}
 
void plot_iv(float *x, float *y, int xsize)
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawLine(10, 218, 318, 218);
  myGLCD.drawLine(10, 15 , 10, 218);

  myGLCD.fillCircle(10,15,5);   //TOP LEFT
  myGLCD.fillCircle(310,15,5);  //TOP RIGHT
  myGLCD.fillCircle(310,218,5); //BOTTOM RIGHT
  myGLCD.fillCircle(10,218,5);  //BOTTOM LEFT

  float xpixel [xsize];
  float ypixel [xsize];

  int i = 0;
  for(i=0;i<xsize;i++)
  {
    xpixel[i] = 10 + x[i] * (310.0 - 10.0)/ (1.0-0.0);
    ypixel[i] = (218.0 - y[i] * (218.0-15.0)/(5.0-0.0) ) ;//          (float) map(y[i],0.0,15.0,15.0,218.0);
    Serial.println(i + String(") ") + xpixel[i]+ String(" || ") + ypixel[i]);
  }
  i=0;
  myGLCD.setColor(255, 255, 0);
  for(i=0;i<(xsize-1);i++)
  {
    myGLCD.drawLine(xpixel[i],ypixel[i],xpixel[i+1],ypixel[i+1]);
  }
  i=0;
  Serial.println("@@@");
  myGLCD.setColor(255, 0, 0);
  for(i=0;i<xsize;i++)
  { 
    
    myGLCD.fillCircle( xpixel[i],ypixel[i],3);
  }
  

}
 

void ask_temps()
{
  myGLCD.print("Please Enter Number Of Temperatures :: ", CENTER, 100);
  int n = 3; //get_input_temp();
//  byte temp_array[n];
  byte temp_array[3] = {65,12,45}; 
  while(n>0)
  {
//    temp_array[n-1] = get_input_temp();
    myGLCD.print(String(temp_array[n-1]), CENTER, 100+n*20);
    n=n-1;
  }
  
  isort(temp_array,sizeof(temp_array));
}
 
float maxNum(float *z, int zsize)
{
  int i = 0;
  int max_val = z[0];
  for (i = 0; i < zsize; i++)
  {
    max_val = max(max_val, z[i]);
  }
  return max_val;
}

float minNum(float *z, int zsize)
{
  int i = 0;
  //  int max_val =*x;
  int min_val = z[0];
  for (i = 0; i < zsize; i++)
  {
    min_val = min(min_val, z[i]);
  }
  return min_val;
}



