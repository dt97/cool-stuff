#define led 13
#define lo 7
#define lf 6
int inputByte;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(lo,OUTPUT);
  pinMode(lf,OUTPUT);
  digitalWrite(lf,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    inputByte=Serial.read();
    delay(10);
    digitalWrite(led,HIGH);
  }
  if(inputByte=='O')
  {
    analogWrite(lo,180);
    Serial.println("ON");
  }
  else if(inputByte=='F')
  {
    digitalWrite(lo,LOW);
    Serial.println("OFF");
  }
}
