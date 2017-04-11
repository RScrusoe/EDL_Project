#include "AH_MCP4921.h"
int diode_pin = A2;
AH_MCP4921 AnalogOutput(51,52,53);
void setup() {
 AnalogOutput.setValue(0);
  pinMode(diode_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i=0; i<4096; i+=8)           //12-bit resolution / 0=>min / 4096=>max
 {
  Serial.print(i,DEC);
  AnalogOutput.setValue(i);           //Update the voltage value
  
  Serial.print(";");
  delay(10);

  int Vd = analogRead(diode_pin);
  delay(10);
  
  Serial.print("AO1="); 
  Serial.print(Vd);
  Serial.print("\t");
  Serial.println();
 }
}
