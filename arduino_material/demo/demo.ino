
#include "SPI.h" // necessary library
#define DATAOUT     11  //MOSI
#define SPICLOCK    13  //sck
#define SLAVESELECT 10  //ss
#define ledPin       2

void set_voltage(float x);    // float x can be any number between 0-5000 i.e. value in milivolts
void print_temp(int tempPin);

int tempPin = A0;

void setup()
{ //set pin(s) to input and output
  //pinMode(10, OUTPUT);
  pinMode(tempPin, INPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}

void loop()
{
  int i = 0;
  for (int i = 0; i <= 5000; i = i + 200) {
    set_voltage(i);
    print_temp(A0);
    delay(2000);
  }
  /* uncomment this to get temperature in farenhite
    Serial.print("TEMPRATURE = ");
    Serial.print(farh);
    Serial.print("*F");
    Serial.println();


  */
}

void set_voltage(float x)
{
  int t;
  word outputValue = 0; // a word is a 16-bit number
  byte data = 0; // and a byte is an 8-bit number
  t = 4096 * x / 5000;
  outputValue = t;
  digitalWrite(10, LOW);
  data = highByte(outputValue);
  data = 0b00001111 & data;
  data = 0b00110000 | data;
  SPI.transfer(data);
  data = lowByte(outputValue);
  SPI.transfer(data);
  digitalWrite(10, HIGH);
  delay(500);
}

void print_temp(int tempPin)
{
  int val;
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
}





