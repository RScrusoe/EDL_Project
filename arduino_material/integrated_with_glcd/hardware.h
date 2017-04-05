#pragma once
#include <Keypad.h>
#include <stdlib.h>
#include <stdio.h>
#include "SPI.h" // necessary library
#define DATAOUT     11  //MOSI
#define SPICLOCK    13  //sck
#define SLAVESELECT 10  //ss
float Vd;
byte data = 0; // and a byte is an 8-bit number
float in_volt;
float current;
float resistor = 1; // in kohms
void send_data(int a);
void print_iv(float Vd);
int diode_pin = A1;
int relay_pin = A4;
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { A5, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3 };
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int freq = 1000;
//float pwm = 0.60;
float max_pwm = 1;
float pwm_step = 0.05;
int pwm_pin = 9;
int duty;
//int timeForOneDC = 1000;   //in miliseconds
int val;
int tempPin = A0;
float temp_setpoint = 15;
float curr_temp,old_temp, error = 0;
float Kp = 0.002;
float Kd = 0;
float Ki = 0;
float initial_temp;
int ct=0;
bool flag=1;
float old_pwm = 0;
float new_pwm = 0;
int current_read_pin = A2;
int lm35_5volt_pin = A3; 
float current_current;

int get_input_temp();
float get_temp();
float find_current();
void isort(byte *a, int n);
int get_input_temp()
{
  
  char key = kpd.waitForKey();
  int temp = 0;
  if (key) // Check for a valid key.
  {
    temp = temp + 10 * (key - 48);
  }
  key = kpd.waitForKey();
  if (key) // Check for a valid key.
  {
    temp = temp +  (key - 48);
  }

  return temp;
}

float find_current()
{
  float x = analogRead(current_read_pin);
  float y = x*5.0/1024.0;
  return(y);
  //return(( 12.8 - (analogRead(current_read_pin)*5.0/1024.0))/0.1);
}

float get_temp()
{
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  return cel;
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
  delay(500);
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

void isort(byte *a, int n)
{
 for (int i = 1; i < n; ++i)
 {
   int j = a[i];
   int k;
   for (k = i - 1; (k >= 0) && (j < a[k]); k--)
   {
     a[k + 1] = a[k];
   }
   a[k + 1] = j;
 }
}

