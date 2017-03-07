/*  Keypadtest.pde

    Demonstrate the simplest use of the  keypad library.

    The first step is to connect your keypad to the
    Arduino  using the pin numbers listed below in
    rowPins[] and colPins[]. If you want to use different
    pins then  you  can  change  the  numbers below to
    match your setup.

  Coneect Pin (1 thru 8 ) of keypad (If we hold keypad facing ourside, leftmost pin is Pin 1)to Arduino Pin (9 thru 2)
  
*/
#include <Keypad.h>
#include <stdlib.h>
#include <stdio.h>

int get_temp();

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
byte rowPins[ROWS] = { 9, 8, 7, 6 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int x = get_temp();
  
  Serial.println(x);
  if(x<16){
    Serial.println("Tere baap ne itna temperature kam kiya tha kya BC???  >:(");
    }
}

int get_temp()
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



