#include <UTFT.h>
 
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
//UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
UTFT myGLCD(ILI9325D_8,38,39,40,41);
int start_pix_x = 15;
int start_pix_y = 15;
float y[6] = {10,20,30,40,50,60};
float x[6] = {60,50,40,30,20,10};
//66    187
//118    149
//170    110
//221    72
//325    -5
//15    225
//
//387    179
//325    133
//263    87
//201    41
//139    -5
//77    -51
 
 
 
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
  myGLCD.print("  RAHUL  ", CENTER, 227);
 
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawRect(0, 14, 319, 225);
 
}
 
void plot(float *x, float *y, int xsize)
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawLine(10, 218, 318, 218);
  myGLCD.drawLine(10, 15 , 10, 218);
 
  myGLCD.fillCircle(180,240,15);
 
//Serial.println(myGLCD.getDisplayXSize());
//Serial.println(myGLCD.getDisplayYSize());
 
 
  int dis_x, dis_y = 0;
 
//  float x_pixel_val = (maxNum(x,xsize) - minNum(x,xsize))/310.0;
//  float y_pixel_val = (maxNum(y,xsize) - minNum(y,xsize))/230.0;
 float x_pixel_val = 5.0/310.0;
 float y_pixel_val = 10.0/210.0;
 
  int i = 0;
  for (i = 0; i < xsize; i++)
  {

    myGLCD.fillCircle(   (int)(start_pix_x + x[i]/x_pixel_val), (240 - ((int)( start_pix_y + y[i]/y_pixel_val  )))  , 3 ) ;
//      myGLCD.fillCircle((int)(start_pix_x  + x[i]/x_pixel_val), 240 - ((int)(start_pix_y  + y[i]/y_pixel_val)), 2);
 Serial.print((int)(start_pix_x  + x[i]/x_pixel_val));
 Serial.print("    ");
 Serial.println( 240 - ((int)(start_pix_y  + y[i]/y_pixel_val)));
   
  }
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
