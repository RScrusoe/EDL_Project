#pragma once
#include "myvars.h"

void tft_init();
void plot_iv( int count);
byte *ask_temps();
float maxNum(float *z, int zsize);
float minNum(float *z, int zsize);
int get_input_temp();
float find_current();
float get_temp();
void send_data(int a);
void print_iv(float Vd);
void achieve_temp(int count, int temp_setpoint);
void isort(byte *a, int n);
void plot_axis();

void tft_init()
{
  myGLCD.clrScr();
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 319, 13);
  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0, 226, 319, 239);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("* PELTIER TEMPERATURE SETTABLE PLATFORM*", CENTER, 1);
  myGLCD.setBackColor(64, 64, 64);
  myGLCD.setColor(255, 255, 0);
  myGLCD.print("YASHASWI  |  RAHUL  | UDAY", CENTER, 227);

  myGLCD.setColor(0, 0, 255);
  //myGLCD.drawRect(0, 14, 319, 225);

}

void plot_axis()
{
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawLine(10, 218, 318, 218);
  myGLCD.drawLine(10, 15 , 10, 218);
}

void plot_iv(int count)
{
  int xsize = 21;
  //  myGLCD.fillCircle(10,15,5);   //TOP LEFT
  //  myGLCD.fillCircle(310,15,5);  //TOP RIGHT
  //  myGLCD.fillCircle(310,218,5); //BOTTOM RIGHT
  //  myGLCD.fillCircle(10,218,5);  //BOTTOM LEFT


  if (count == 0) {myGLCD.setColor(255, 102, 0);}
  else if (count == 0) {myGLCD.setColor(255, 255, 0);}
  else if (count == 0) {myGLCD.setColor(0, 255, 0);}
  else if (count == 0) {myGLCD.setColor(26, 255, 255);}
  else if (count == 0) {myGLCD.setColor(255, 26, 255);}

  float xpixel [xsize];
  float ypixel [xsize];

  int i = 0;
  for (i = 0; i < xsize; i++)
  {
    xpixel[i] = 10 + iv_data[2 * count][i] * (310.0 - 10.0) / (1.0 - 0.0);
    ypixel[i] = (218.0 - iv_data[2 * count + 1][i] * (218.0 - 15.0) / (5.0 - 0.0) ) ; //          (float) map(y[i],0.0,15.0,15.0,218.0);
    Serial.println(i + String(") ") + xpixel[i] + String(" || ") + ypixel[i]);
  }
  i = 0;

  for (i = 0; i < (xsize - 1); i++)
  {
    myGLCD.drawLine(xpixel[i], ypixel[i], xpixel[i + 1], ypixel[i + 1]);
  }
  i = 0;
  //Serial.println("@@@");
  //myGLCD.setColor(255, 0, 0);
  for (i = 0; i < xsize; i++)
  {
    myGLCD.fillCircle( xpixel[i], ypixel[i], 3);
  }


  i = 0;
  Serial.print("Voltages = {");
  for (i = 0; i < xsize; i++)
  {
    Serial.print(String(iv_data[2 * count][i]) + ", ");
  }
  Serial.println();
  Serial.print("Currents = {");
  i = 0;
  for (i = 0; i < xsize; i++)
  {
    Serial.print(String(iv_data[2 * count + 1][i]) + ", ");
  }
  Serial.println();

  myGLCD.print(temp_array[count] + "*C", 25, 25 + 10 * count);

}

byte * ask_temps()
{
  myGLCD.print("Please Enter Number Of Temperatures :: ", CENTER, 100);
  int n = get_input_temp();
  tft_init();
  Serial.println(n);
  myGLCD.print("You Entered -> " + String(n), CENTER, 50);
  //  byte temp_array[n];
  //  byte temp_array[3] = {65,12,45};
  int t = n;
  for (int i = 0; i < t; i++)
  {
    temp_array[i] = get_input_temp();
    Serial.println(String(temp_array[i]) + "*C");
    myGLCD.print(String(temp_array[i]) + "*C", CENTER, 70 + i * 20);
  }
  //  while(n>0)
  //  {
  //
  //    temp_array[n-1] = get_input_temp();
  //    Serial.println((int)temp_array[n-1] + "*C");
  //    myGLCD.print(String(temp_array[n-1]) + "*C", CENTER, 50+n*20);
  //    n=n-1;
  //  }

  isort(temp_array, n);

  for (int i = 0; i < t; i++) {
    Serial.println(temp_array[i]);
  }

  delay(2000);
  return n;

}

float maxNum(float *z, int zsize)
{
  int i = 0;
  int max_val = z[0];
  for (i = 0; i < zsize; i++)
  {
    max_val = max(max_val, z[i]);
  }
  return max_val;
}

float minNum(float *z, int zsize)
{
  int i = 0;
  //  int max_val =*x;
  int min_val = z[0];
  for (i = 0; i < zsize; i++)
  {
    min_val = min(min_val, z[i]);
  }
  return min_val;
}

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
  float y = x * 5.0 / 1024.0;
  return (y);
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

void achieve_temp(int count, int temp_setpoint)
{
  int z = 0;
  float currx,curry;
  float prevx,prevy; 
  int flag2 = 0;
  float tmp_time = millis() / 1000.0;
  if (count == 0) {myGLCD.setColor(255, 102, 0);}
  else if (count == 0) {myGLCD.setColor(255, 255, 0);}
  else if (count == 0) {myGLCD.setColor(0, 255, 0);}
  else if (count == 0) {myGLCD.setColor(26, 255, 255);}
  else if (count == 0) {myGLCD.setColor(255, 26, 255);}

  initial_temp = get_temp();
  Serial.println("Current Temp = " + String(initial_temp) + "*C   ||  " + "Temp Setpoint = " + String(temp_setpoint) + "*C");
  if (initial_temp > temp_setpoint)
  {
    Serial.println("Writing Relay -> LOW");
    analogWrite(relay_pin, 0);
  }
  else
  {
    Serial.println("Writing Relay -> HIGH");
    analogWrite(relay_pin, 255);
  }
  curr_temp = get_temp();
  error = temp_setpoint - curr_temp;
  prev_error = error;
  if (error < 0)
  {
    flag = 0;
    error = error * (-1);
    prev_error = error;
  }


  while (abs(error) >= 2 || ct <= 1)
  {
    curr_time = millis() / 1000.0 - tmp_time;
    old_temp = curr_temp;
    currx = 10.0 + curr_time * (310.0 - 10.0) / 1000.0;
    curry = 218.0 - curr_temp * (218.0 - 15.0) / (70.0 - 5.0);
    if (!flag2) 
    {
      prevx = currx;
      prevy = curry;
      flag2 = 1;
    }
    myGLCD.drawLine(prevx,prevy,currx,curry);
    myGLCD.fillCircle(currx , curry , 2 ); // Assuming max time takes is 1000s;
    prevx = currx;
    prevy = curry;
    new_pwm = old_pwm + error * Kp; // + Kd*(error-prev_error));
    prev_error = error;
    if (new_pwm >= 1)
    {
      new_pwm = 0.95;
    }
    //duty = 0.99 * 255;
    duty = new_pwm * 255;
    analogWrite(pwm_pin, duty);
    current_current = find_current();
    Serial.print(duty);
    Serial.print("  ||  current = ");
    Serial.print(current_current);
    Serial.print("V  ||  time in secs: ");
    Serial.print(curr_time);
    Serial.print("  ||  ");
    Serial.print(curr_temp);
    Serial.print("  ||  ");
    Serial.println(new_pwm);
    delay(10000);
    curr_temp = get_temp();
    if (!flag)
    {
      error = curr_temp - temp_setpoint;
    }
    else
    {
      error = temp_setpoint - curr_temp;
    }
    old_pwm = new_pwm;
    if (ct >= 1 && abs(temp_setpoint - curr_temp) > 2) {ct = 0;}
    if (abs(temp_setpoint - curr_temp) < 2) {ct = ct + 1;}

  }
  Serial.println("Done!!!");
  Serial.print("Setting duty at "); Serial.println(new_pwm);
  Serial.print("Maintaining Temperature at "); Serial.print(temp_setpoint); Serial.println(" *C");
  analogWrite(pwm_pin, duty);

  analogWrite(trigger,255);
//delay(1500);

  for (int a = 0; a <= 4095; a = a + 200 )
  {
    in_volt = a;
//    send_data(a);
    Vd = analogRead(diode_pin);
    Vd = (Vd / 1024.0) * 5.0;
    in_volt = (in_volt / 4096.0) * 5.0;
    current = (in_volt - Vd) / resistor;
    Serial.println(String(Vd) + " || " + String(current));
    iv_data[2 * count][z] = Vd;
    iv_data[2 * count + 1][z] = current;
    z= z+1;
    //    print_iv(Vd);
  }
  Serial.println();

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
