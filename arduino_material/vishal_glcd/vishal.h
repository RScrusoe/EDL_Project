#include <UTFT.h>
extern uint8_t SmallFont[];
UTFT myGLCD(ILI9341_16,38,39,40,41);

void screen_init()
{
  myGLCD.clrScr();
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 399, 13);
  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0, 226, 399, 239);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("     ***** PORTABLE BJT TESTER *****      ", CENTER, 1);
  myGLCD.setBackColor(64, 64, 64);
  myGLCD.setColor(255,255,0);
  myGLCD.print("     By:Vishal Raut| Guide:Prof J.John     ", CENTER, 227);
}
void IV_graph(){
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawLine(10, 215, 318, 215);
  myGLCD.drawLine(10, 15 , 10, 215);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.print(" 0      1       2       3       4 (Vce)5", CENTER, 217);
  myGLCD.print("Ic",LEFT,17);
  myGLCD.print("9",LEFT,30);
  myGLCD.print("7",LEFT,70);
  myGLCD.print("mA",LEFT,90);
  myGLCD.print("5",LEFT,110);
  myGLCD.print("3",LEFT,150);
  myGLCD.print("1",LEFT,190);
  myGLCD.setColor(VGA_LIME);
  myGLCD.fillRoundRect(240,15,319,200);
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(VGA_LIME);
  myGLCD.print("Ic:",RIGHT,20);
  myGLCD.print("Ib:",RIGHT,35);
  myGLCD.print("Beta:",RIGHT,50);
}

