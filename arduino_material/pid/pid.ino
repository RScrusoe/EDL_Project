#include "myfiles.h"

void setup()
{
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //analogWrite(pwm_pin, duty);
  curr_temp = get_temp();
  error = temp_setpoint - curr_temp;
  if (error<0)
  {
    flag = 0;
    error = error * (-1);
  }
  while (abs(error) >=2 || ct <=5)
  {
    
    old_temp = curr_temp;
    
    new_pwm = old_pwm + error * Kp;
    if (new_pwm >= 1) 
    {
      new_pwm = 0.95;
    }
    duty = new_pwm * 255;
    Serial.print(duty);
    Serial.print("  ||  ");
    analogWrite(pwm_pin, duty);
    Serial.println(new_pwm);
    delay(30000);
    curr_temp = get_temp();
    
    if(!flag)
    {
      error = curr_temp - temp_setpoint;
    }
    else
    {
      error = temp_setpoint - curr_temp;
    }
    old_pwm = new_pwm;
    if (abs(old_temp - curr_temp) < 2){ct= ct + 1;}
    
  }
Serial.println("Done!!");
while(1)
{
  analogWrite(pwm_pin, duty);
}




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




