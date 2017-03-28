#include "myvars.h"

void setup()
{
  //pinMode(relay_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
  pinMode(diode_pin, INPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}

void loop()
{ 
  initial_temp = get_temp();
//  Serial.println("Enter input Temperature using keypad:: ");
//  temp_setpoint = get_input_temp();
    Serial.println(temp_setpoint);
    
  
  if(initial_temp>temp_setpoint)
  {
    digitalWrite(relay_pin,LOW);
  }
  else
  {
    digitalWrite(relay_pin,HIGH);
  }
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
    
    analogWrite(pwm_pin, duty);
    
    Serial.print(duty);
    Serial.print("  ||  time in secs: ");
    Serial.print((millis())/1000.0);  
    Serial.print("  ||  ");
    Serial.print(curr_temp);
    Serial.print("  ||  ");
    Serial.println(new_pwm);
    delay(20000);
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
    if(ct >= 1 && abs(temp_setpoint - curr_temp) > 2){ct=0;}
    if (abs(temp_setpoint - curr_temp) < 2){ct= ct + 1;}
    
  }
  Serial.println("Done!!!");
  Serial.print("Setting duty at ");Serial.println(new_pwm);
  Serial.print("Maintaining Temperature at "); Serial.print(temp_setpoint); Serial.println(" *C");
  analogWrite(pwm_pin, duty);  
    for (int a = 0; a <= 4095; a = a + 50 )
  { 
    in_volt = a;
    send_data(a);
    Vd = analogRead(diode_pin);
    print_iv(Vd);
  }
  Serial.println();
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


