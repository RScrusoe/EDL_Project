int freq = 1000;
//float pwm = 0.60;
float max_pwm = 1;
float pwm_step = 0.05;
int pwm_pin = 9;
int duty;
//int timeForOneDC = 1000;   //in miliseconds
int val;
int tempPin = A0;
float temp_setpoint = 60;
float curr_temp,old_temp, error = 0;
float Kp = 0.002;
float Kd = 0;
float Ki = 0;
int ct=0;
bool flag=1;
float old_pwm = 0;
float new_pwm = 0;

float get_temp();



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
