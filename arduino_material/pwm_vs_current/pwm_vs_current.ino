float pwm = 0.0;
float max_pwm = 1;
float pwm_step = 0.025;
int ledpin = 9;
int duty;
int val;
int tempPin = A0;
float get_temp();
int current_read_pin = A4;
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(current_read_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{ 
  float current = 0;
//  analogWrite(ledpin, pwm*255);
// float curr_temp = get_temp();
  while (1) 
  {
    duty = pwm * 255;
    if (duty >= 255) 
    {
      pwm = 0.0;
    }

    analogWrite(ledpin, duty);
    //3.882736
    current = (12 - (3.882736 * (analogRead(current_read_pin)*5.0/1024.0)))/0.1;
    Serial.println(String(pwm) + "    " + String((analogRead(current_read_pin)*5.0/1024.0)) +"    " + String(current));
    delay(5000);    
    pwm = pwm + pwm_step;
  }

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
