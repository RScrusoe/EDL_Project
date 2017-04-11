#pragma once
#include "myfuncs.h"
#include <Keypad.h>
#include <stdlib.h>
#include <stdio.h>
#include "AH_MCP4921.h"
AH_MCP4921 AnalogOutput(51,52,53);
//#include "SPI.h" // necessary library
//#define DATAOUT     51 //51 for Mega   //11for UNO //MOSI    //MCP Pin 4
//#define SPICLOCK    52 //52 for Mega   // 13 for UNO //sck   //MCP Pin 3
//#define SLAVESELECT 53 //53 for Mega   //10  for UNO  //ss   //MCP Pin 2
#include <UTFT.h>
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
//float x[82] = {0,0.05,0.11,0.17,0.23,0.29,0.35,0.4,0.44,0.47,0.49,0.51,0.53,0.54,0.55,0.56,0.57,0.57,0.58,0.59,0.59,0.59,0.6,0.6,0.61,0.61,0.61,0.62,0.62,0.62,0.63,0.63,0.63,0.63,0.63,0.63,0.64,0.64,0.64,0.64,0.65,0.65,0.65,0.65,0.65,0.66,0.66,0.66,0.66,0.66,0.66,0.66,0.67,0.67,0.67,0.67,0.67,0.67,0.67,0.68,0.68,0.68,0.68,0.68,0.68,0.68,0.68,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69,0.69};
//float y[82] = {0,0.01,0.01,0.02,0.01,0.01,0.02,0.03,0.05,0.08,0.12,0.16,0.21,0.26,0.3,0.36,0.41,0.47,0.52,0.57,0.63,0.69,0.75,0.8,0.86,0.92,0.98,1.03,1.09,1.15,1.21,1.26,1.32,1.38,1.44,1.5,1.56,1.62,1.68,1.74,1.79,1.85,1.91,1.97,2.03,2.09,2.15,2.21,2.27,2.33,2.39,2.45,2.5,2.57,2.63,2.68,2.74,2.81,2.87,2.92,2.98,3.04,3.11,3.16,3.22,3.28,3.34,3.4,3.46,3.52,3.58,3.65,3.71,3.77,3.83,3.89,3.95,4.01,4.07,4.13,4.19,4.26};


float prevx,prevy = 0;
 

float Vd;
byte data = 0; // and a byte is an 8-bit number
float in_volt;
float current;
float resistor = 0.33; // in kohms
int diode_pin = A2;
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
byte rowPins[ROWS] = { A15, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3 };
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int pwm_pin = 9;
int duty;
int val;
int tempPin = A0;
float temp_setpoint = 15;
float curr_temp,old_temp, error = 0;
float Kp = 0.002;
float Kd = 0.01;
float Ki = 0;
float initial_temp;
int ct=0;
bool flag=1;
float old_pwm = 0;
float new_pwm = 0;
int current_read_pin = A5;
int lm35_5volt_pin = A3; 
float current_current;
float curr_time,prev_error=0;
float iv_data[10][21];
byte  temp_array[5] = {0,0,0,0,0};

