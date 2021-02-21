
const int enable_L = 11;
const int enable_R = 10;
const int MotorLeft_A = 9;
const int MotorLeft_B = 8;
const int MotorRight_A = 6;
const int MotorRight_B = 7;
const int IR_Left = 5;
const int IR_Right = 4;
int IR_L;
int IR_R;

void setup() 
{
    pinMode(enable_L,OUTPUT);
    pinMode(enable_R,OUTPUT);
    pinMode(MotorLeft_A,OUTPUT);
    pinMode(MotorLeft_B,OUTPUT);
    pinMode(MotorRight_A,OUTPUT);
    pinMode(MotorRight_B,OUTPUT);
    pinMode(IR_Right,INPUT);
    pinMode(IR_Left,INPUT);
    pinMode(3,OUTPUT);
    digitalWrite(3,HIGH);
    Serial.begin(9600);
}

void loop() 
{
    IR_R=digitalRead(IR_Right);
    IR_L=digitalRead(IR_Left);
    Serial.print(IR_R);
    Serial.print("----");
    Serial.println(IR_L);
    if(IR_R==LOW && IR_L==LOW)//FORWARD
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
    }
    if(IR_R==LOW && IR_L==HIGH)//LEFT TURN
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
      delay(200);
    }
    if(IR_R==HIGH && IR_L==LOW)//RIGHT
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      delay(200);
    }
    if(IR_R==HIGH && IR_L==HIGH)
    {
      digitalWrite(enable_L,LOW);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,LOW);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
//      delay(500);
    }
    
    
}
