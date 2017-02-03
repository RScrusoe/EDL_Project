
#include "SPI.h" // necessary library
#define DATAOUT     11  //MOSI
#define SPICLOCK    13  //sck
#define SLAVESELECT 10  //ss
#define ledPin       2
float xx;
int del=20; // used for various delays
word outputValue = 0; // a word is a 16-bit number
byte data = 0; // and a byte is an 8-bit number
int ct = 0;
float a1;
float current;
void setup()
{
  //set pin(s) to input and output
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}
 
void loop()
{
 
  for (int a=0; a<=4095; a = a +10 )
  { ct = ct +1;
    outputValue = a;
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
    delay(500);
    xx=analogRead(A0);
   // Serial.print(xx);
   xx = (xx/1024) * 5;
   a1 = a;
   a1 = (a1/4096) * 5;
    //xx = map(xx,0,1023,0,5);
    //a1 = map(a,0,4095,0,5);
    current = (a1- xx)/0.3;
    
    Serial.print(a1);
    Serial.print("\t");
    
    Serial.print(xx);
    Serial.print("\t");
    Serial.println(current);
    
  }
  Serial.println("@@@");
  Serial.print(ct);
  while(1){}
  delay(del*25);
//  for (int a=4095; a>=0; --a)
//  {
//    outputValue = a;
//    digitalWrite(10, LOW);
//    data = highByte(outputValue);
//    data = 0b00001111 & data;
//    data = 0b00110000 | data;
//    SPI.transfer(data);
//    data = lowByte(outputValue);
//    SPI.transfer(data);
//    digitalWrite(10, HIGH);
//    delay(del);
//  }
//  delay(del+25);
}
