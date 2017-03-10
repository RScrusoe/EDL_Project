int freq = 1000;
float pwm = 0.60;
float max_pwm = 1;
float pwm_step = 0.05;
int pwm_pin = 9;
int duty;
int timeForOneDC = 1000;   //in miliseconds
int val;
int tempPin = A0;
int volt_out = 4.5;
float temp_setpoint = 20;
float curr_temp,old_temp, error = 0;
float Kp = 0.01;
float Kd = 0;
float Ki = 0;
int ct=0;
bool flag;
float old_pwm = 0;
float new_pwm = 0;

float get_temp();
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
    analogWrite(pwm_pin, duty);
    Serial.println(new_pwm);
    delay(60000);
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
    if (abs(old_temp - curr_temp) < 4){ct= ct + 1;}
    
  }
Serial.println("Done bhenchod!!");
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

