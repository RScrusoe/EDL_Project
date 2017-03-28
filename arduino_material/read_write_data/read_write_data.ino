//void setup() {
//  Serial.begin(9600);
//}
//void loop() {
//  if(Serial.available() > 0) {
//    char data = Serial.read();
//    char str[2];
//    str[0] = data;
//    str[1] = "\0";
//    Serial.print(str);
//  }
//}


void setup() {
  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once
}
void loop() {
  char inByte = ' ';
  if (Serial.available()) { // only send data back if data has been sent
    char inByte = Serial.read(); // read the incoming data
    Serial.println(inByte); // send the data back in a new line so that it is not all one long line
  }
  delay(100); // delay for 1/10 of a second
}
