#include "my.h"

int x[5] = {1,2,3,4,0};

void setup(){
  Serial.begin(9600);
  //randomSeed(11);

}

void loop(){
  
  //def();
  //Serial.println(randNumber);
  Serial.println(minNum(x,5));
  delay(500);
}

