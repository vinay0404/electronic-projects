
const int enable_L = 11;
const int enable_R = 10;
const int MotorLeft_A = 9;
const int MotorLeft_B = 8;
const int MotorRight_A = 6;
const int MotorRight_B = 7;
int x;
int y;

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
      x=analogRead(A0);
      y=analogRead(A1);
      Serial.print("x-axis");
      Serial.print(x);
      Serial.print("Y-axis");
      Serial.println(y);
     // delay(500);
      if((x>300&&x<350)&&(y>351&&y<400))//FORWARD
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
    }
    if((y>300&&y<350)&&(x>251&&x<300))//LEFT TURN
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
      delay(200);
    }
   if((y>300&&y<350)&&(x>351&&x<400))//RIGHT
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      delay(200);
    }
      if((y>300&&y<350)&&(x>300&&x<350))//STOP
    {
      digitalWrite(enable_L,LOW);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,LOW);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
//      delay(500);
    }
     if((y>250&&y<300)&&(x>300&&x<350))//REVERSE
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
