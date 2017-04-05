#include "myvars.h"

void setup()
{
  pinMode(relay_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(diode_pin, INPUT);
  pinMode(current_read_pin, INPUT);
  pinMode(lm35_5volt_pin, OUTPUT);
  analogWrite(lm35_5volt_pin,255);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Enter input Temperature using keypad:: ");
  temp_setpoint = get_input_temp();
  Serial.println(temp_setpoint);
  achieve_temp(temp_setpoint);  
//Serial.print(ct);
  while (1) {}
//while(1)
//{
  
  
//}
  //  while (1)
  //  {
  //    duty = pwm * 255;
  //    if (duty >= 255)
  //    {
  //      pwm = 0.0;
  //    }
  //
  //    analogWrite(pwm_pin, duty);
  //    delay(2000);
  //    pwm = pwm + pwm_step;
  //  }

}


