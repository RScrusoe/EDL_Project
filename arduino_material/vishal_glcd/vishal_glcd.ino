#include <SPI.h>
#include <UTFT.h>
#include "vishal.h"
const int SSBase = 10;
const int SSCollector = 9;
const int sweepbase = 5;
const int sweepcollector = 50;
const int VCE_Pin = 0;
const int VCC_Pin = 1;
const int VBE_Pin = 2;
const int VBB_Pin = 3;
int vceValue = 0;
int vccValue = 0;
int vbeValue = 0;
int vbbValue = 0;
int vstepbase = 4095/sweepbase;
int vstepcollector = 4095/sweepcollector;
float vce = 0;
float vbb = 0;
float vcc = 0;
float vbe = 0;

float Rcollector = 220.0; //Collector resistance (ohm)
float Rbase = 99900.0; //Base resistance (ohm)
float Icollector = 0; //Collector current
float Ibase = 0; // Collector base

void setup() {
  
  pinMode(SSBase,OUTPUT);
  pinMode(SSCollector,OUTPUT);
  
  //Initialize the SPI Bus
  SPI.begin();
  //Transfer MSB first according to the MP4921 datasheet
  SPI.setBitOrder(MSBFIRST);
  
  //Set initial values for VBB and VCC (avoids some problems
  // with the first values to be read)
  dacTransfer(SSBase, 1);
  dacTransfer(SSCollector, 1);
  
  //Initialize serial 
  Serial.begin(9600);
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop() {
  screen_init();
  IV_graph();
  for (int i=vstepbase; i <= 4095; i=i+vstepbase){
   for (int j=vstepcollector; j <= 4095; j=j+vstepcollector){
     dacTransfer(SSBase, i);
     dacTransfer(SSCollector, j);
     delay(100);
     readValues();
       }  
     }
}

void dacTransfer(int slaveNumber, int value){
// 16-bit value is splitted into two bytes
// 4 most significant bits correspond to configuration of the DAC
// 12 least significant bits correspond to 12-bit data

  byte upperData = 0x30;  // Set the 4 configuration bits
  byte lowerData = 0x00;
  word dataWord; // The 16-bit word to be written
  
  dataWord = value;
  lowerData = lowByte(dataWord);

//transfer the 4 most significant bits of data to the upper byte
  upperData |= highByte(dataWord); 
  
//Select the DAC
  digitalWrite(slaveNumber,LOW);
  
//Transfer the data
  SPI.transfer(upperData);
  SPI.transfer(lowerData);
  
//DAC is unselected
  digitalWrite(slaveNumber,HIGH);
}

void readValues() {

//Read the values at the analog inputs
  vbbValue = analogRead(VBB_Pin);
  vbeValue = analogRead(VBE_Pin);
  vccValue = analogRead(VCC_Pin);
  vceValue = analogRead(VCE_Pin);
  
//Convert to volts  
  vce=(float)vceValue*5./1023.;
  vcc=(float)vccValue*5./1023.;
  vbb=(float)vbbValue*5./1023.;
  vbe=(float)vbeValue*5./1023.;
  
//Calculate collector and base currents
  Icollector=(vcc-vce)/Rcollector*1000.;
  Ibase=(vbb-vbe)/Rbase*1000000.;
  
//Print to serial output
// VCC, VBB, VBE, IC (mA), IB (uA)
  Serial.print(vcc);
  Serial.print("\t");
  Serial.print(vbb);
  Serial.print("\t");
  Serial.print(vbe);
  Serial.print("\t");
  Serial.print(vce);
  Serial.print("\t");
  Serial.print(Icollector);
  Serial.print("\t");
  Serial.print(Ibase);

  Serial.println();

  delay(1000);
}
