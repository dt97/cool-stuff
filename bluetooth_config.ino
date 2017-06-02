#define led 13
#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);//RX,TX CONNECT (10,11) RX WITH TX OF HC05 AND VICE-VERSA FOR TRANSFER...
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(38400);//hc05 baud rate at AT command mode
  pinMode(led,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.println("Enter AT commands");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available())
  {
    Serial.write(mySerial.read());
    digitalWrite(led,HIGH);
  }
  else if(Serial.available())
  {
    mySerial.write(Serial.read());
    digitalWrite(led,HIGH);
  }
}
