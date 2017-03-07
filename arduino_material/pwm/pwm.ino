int freq = 1000;
float pwm = 0.0;
float max_pwm = 1;
float pwm_step = 0.05;
int ledpin = 9;
int duty;
int timeForOneDC = 1000;   //in miliseconds
void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (1) 
  {
    duty = pwm * 255;
    if (duty >= 255) 
    {
      pwm = 0.0;
    }

    analogWrite(ledpin, duty);
    delay(2000);
    pwm = pwm + pwm_step;
  }

}
