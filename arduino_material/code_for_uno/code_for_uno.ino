
#include "SPI.h" // necessary library
#define DATAOUT     11  //MOSI
#define SPICLOCK    13  //sck
#define SLAVESELECT 10  //ss
float Vd;
byte data = 0; // and a byte is an 8-bit number
void send_data(int a);
int trigger = A10;
void setup()
{
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  pinMode(trigger, INPUT);
  Serial.begin(9600);
}

void loop()
{

  if(analogRead(trigger) > 900)
  {
     for (int a = 0; a <= 4095; a = a + 200 )
    { 
      send_data(a);
    } 
  }
  
}



void send_data(int a)
{
  digitalWrite(10, LOW);
  data = highByte(a);
  data = 0b00001111 & data;
  data = 0b00110000 | data;
  SPI.transfer(data);
  data = lowByte(a);
  SPI.transfer(data);
  digitalWrite(10, HIGH);
  delay(1000);
}

