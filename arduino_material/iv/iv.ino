
#include "SPI.h" // necessary library
#define DATAOUT     11  //MOSI
#define SPICLOCK    13  //sck
#define SLAVESELECT 10  //ss
float Vd;
byte data = 0; // and a byte is an 8-bit number
float in_volt;
float current;
float resistor = 0.33; // in kohms
void send_data(int a);
void print_iv(float Vd);
int diode_pin = A0;
void setup()
{
  //set pin(s) to input and output
  pinMode(diode_pin, INPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}

void loop()
{

  for (int a = 0; a <= 4095; a = a + 50 )
  { 
    in_volt = a;
    send_data(a);
    Vd = analogRead(diode_pin);
    print_iv(Vd);
  }
  //Serial.print(ct);
  while (1) {}
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

void print_iv(float Vd)
{
    Vd = (Vd / 1024) * 5;
    in_volt = (in_volt / 4096) * 5;
    current = (in_volt - Vd) / resistor;
    Serial.print(in_volt);
    Serial.print("\t");
    Serial.print(Vd);
    Serial.print("\t");
    Serial.println(current);

}

