#define led 13
#define l1 7
#define l2 8
#define r1 10
#define r2 11
#define pwml 6
#define pwmr 9
#define sl1 4
#define sr1 5
#define pwms 3
int inputByte=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(pwml,OUTPUT);
  pinMode(pwmr,OUTPUT);
  pinMode(sl1,OUTPUT);
  pinMode(sr1,OUTPUT);
  pinMode(pwms,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    inputByte=Serial.read();
    delay(10);
    digitalWrite(led,HIGH);
    if(inputByte=='F')
    {
      forward();
    }
    else if(inputByte=='B')
    {
      back();
    }
    else if(inputByte=='L')
    {
      left();
    }
    else if(inputByte=='R')
    {
      right();
    }
    else if(inputByte=='G')
    {
      fleft();
    }
    else if(inputByte=='I')
    {
      fright();
    }
    else if(inputByte=='H')
    {
      bleft();
    }
    else if(inputByte=='J')
    {
      bright();
    }
    else if(inputByte=='X')
    {
      shoot();
    }
    else if(inputByte=='x')
    {
      sstop();
    }
    else if(inputByte=='S')
    {
      fstop();
    }
    else if(inputByte==' ')
    {
      fstop();
    }
   }    
}
void forward()
{
  analogWrite(pwml,240);
  analogWrite(pwmr,240);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void back()
{
  //analogWrite(pwml,pwm);
  //analogWrite(pwmr,pwm);
  analogWrite(pwml,240);
  analogWrite(pwmr,240);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void left()
{
  analogWrite(pwml,240);
  analogWrite(pwmr,240);
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void right()
{
  analogWrite(pwml,240);
  analogWrite(pwmr,240);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}
void fleft()
{
  analogWrite(pwml,190);
  analogWrite(pwmr,240);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void fright()
{
  analogWrite(pwml,240);
  analogWrite(pwmr,190);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void bleft()
{
  analogWrite(pwml,190);
  analogWrite(pwmr,240);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void bright()
{
  analogWrite(pwml,240);
  analogWrite(pwmr,190);
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void shoot()
{
  analogWrite(pwms,180);
  digitalWrite(sl1,LOW);
  digitalWrite(sr1,HIGH);
  delay(260);
  analogWrite(pwms,180);
  digitalWrite(sl1,HIGH);
  digitalWrite(sr1,LOW);
  delay(120);
  digitalWrite(sl1,LOW);
  digitalWrite(sr1,LOW);
}
void sstop()
{
  digitalWrite(sl1,LOW);
  digitalWrite(sr1,LOW);
}
void fstop()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(sl1,LOW);
  digitalWrite(sr1,LOW);
}
