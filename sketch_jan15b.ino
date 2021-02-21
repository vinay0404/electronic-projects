void setup(){ 
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
  // put your setup code here, to run once:

}


void loop() {
digitalWrite(3,HIGH);
int a=digitalRead(5);
Serial.println(a);
if(5=HIGH)
{
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  int b=digitalRead(9);
  Serial.print(b);
  int c=digitalRead(10);
  Serial.print(c);
}
else if(5=LOW)
{
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  int b=digitalRead(9);
  Serial.print(b);
  int c=digitalRead(10);
  Serial.print(c);
}
  // put your main code here, to run repeatedly:

}
