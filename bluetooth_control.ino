
const int enable_L = 11;
const int enable_R = 10;
const int MotorLeft_A = 9;
const int MotorLeft_B = 8;
const int MotorRight_A = 6;
const int MotorRight_B = 7;

int BT;


void setup() 
{
    pinMode(enable_L,OUTPUT);
    pinMode(enable_R,OUTPUT);
    pinMode(MotorLeft_A,OUTPUT);
    pinMode(MotorLeft_B,OUTPUT);
    pinMode(MotorRight_A,OUTPUT);
    pinMode(MotorRight_B,OUTPUT);
    Serial.begin(9600);
}
void loop() 

{
  if(Serial.available() > 0)
      BT=Serial.read();
  if(BT==85)//FORWARD
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
    }
    if(BT==76)//LEFT TURN
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
      
    }
    if(BT==82)//RIGHT
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
    //  delay(200);
    }
    if(BT==67)//STOP
    {
      digitalWrite(enable_L,LOW);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,LOW);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
//      delay(500);
    }
    if(BT==68)//REVERSE
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
//      delay(500);
    }
}
