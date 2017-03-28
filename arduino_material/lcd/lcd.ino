#include <LiquidCrystal.h>
#define Vref 255   
#define E_PIN 4
#define B_PIN 3
#define C_PIN 5
#define E_READ_PIN A0
#define B_READ_PIN A1
#define C_READ_PIN A2
#define BB_PIN     A3
#define SETTLE_DELAY 50

LiquidCrystal lcd(6, 7, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2); 
  setWaiting();
}
void loop() {
  testForPNP() || testForNPN() || setFailedResult()||setB();
  delay(500);
}
boolean testForNPN() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  int bemV;
  
  analogWrite(B_PIN, 255);
  analogWrite(E_PIN, 0);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  bemV = (ebaseReading - emitterReading);
  if(bemV > 10) {
    setResult(1, bemV);
    return true;
  } else {
    return false;
  }
}
boolean testForPNP() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  int bemV;
  
  analogWrite(B_PIN, 0);
  analogWrite(E_PIN, 255);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  bemV = (ebaseReading - emitterReading);
  if( bemV < -10) {
    setResult(2, bemV);
    return true;
  } else {
    return false;
  }
  
}

void setWaiting() {
  lcd.clear();
  lcd.print("Insert a BJT..");
}
  
void setResult(int bjt_type, int vf) {
  lcd.clear();
  switch(bjt_type) {
  case 1: // NPN
    lcd.print("NPN");
    break;
  case 2:
    lcd.print("PNP");
    break; // PNP
    case 3:
    lcd.print("CBS");
    break; // CBS
    case 4:
    lcd.print("EBS");
    break; // EBS
  default: // unidentified
    lcd.print("ITTB's  PORTABLE");
    lcd.setCursor(0, 1);
    lcd.print("   BJT TESTER   ");
    return;
  }
  lcd.setCursor(4, 0);
  lcd.print("Vs=");
  lcd.print(vf);
  lcd.print("mV");
}
boolean setFailedResult() {
  int ebaseReading;
  int cbaseReading;
  int emitterReading;
  int collectorReading;
  int bemV;
  int bcmV;
  analogWrite(B_PIN, 0);
  analogWrite(E_PIN, 255);
  delay(SETTLE_DELAY);
  ebaseReading = analogRead(B_READ_PIN);
  emitterReading = analogRead(E_READ_PIN);
  analogWrite(C_PIN, 255);
  delay(SETTLE_DELAY);
  cbaseReading = analogRead(B_READ_PIN);
  collectorReading = analogRead(C_READ_PIN);
  bemV = (ebaseReading - emitterReading);
  bcmV = (cbaseReading - collectorReading);
  
  if(bemV = 0) {
    setResult(3, 0);
    return true;
    }else if(bcmV = 0 ) {
    setResult(4, 0);
    return true;
    }else {
      return false;
  }
}
boolean setB() {
  setResult(0,0);
  return true;
}
  

