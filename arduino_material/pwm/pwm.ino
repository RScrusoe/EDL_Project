int freq = 1000;
float pwm = 0.60;
float max_pwm = 1;
float pwm_step = 0.05;
int ledpin = 9;
int duty;
int val;
int tempPin = A0;
int timeForOneDC = 1000;   //in miliseconds
float get_temp();
void setup()
{
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(ledpin, duty);
  float curr_temp = get_temp();
//  while (1) 
//  {
//    duty = pwm * 255;
//    if (duty >= 255) 
//    {
//      pwm = 0.0;
//    }
//
//    analogWrite(ledpin, duty);
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
