#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CNS, CE



const int enable_L = 7;
const int enable_R = 6;
const int MotorLeft_A = 5;
const int MotorLeft_B = 4;
const int MotorRight_A = 2;
const int MotorRight_B = 3;
const int IR_Left = A0;
const int IR_Right = A1;
int IR_L;
int IR_R;


const byte address[6] = "00001";

void setup() {
  pinMode(enable_L,OUTPUT);
    pinMode(enable_R,OUTPUT);
    pinMode(MotorLeft_A,OUTPUT);
    pinMode(MotorLeft_B,OUTPUT);
    pinMode(MotorRight_A,OUTPUT);
    pinMode(MotorRight_B,OUTPUT);
    pinMode(IR_Right,INPUT);
    pinMode(IR_Left,INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
    IR_R=digitalRead(IR_Right);
    IR_L=digitalRead(IR_Left);

    if(IR_R==LOW && IR_L==LOW)//FORWARD
  {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      char text[]="FORWARD";
      radio.write(&text, sizeof(text));
      delay(1000);
  }
    if(IR_R==LOW && IR_L==HIGH)//LEFT TURN
  {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
      char text[]="LEFT";
      radio.write(&text, sizeof(text));
      delay(1000);
  }
    if(IR_R==HIGH && IR_L==LOW)//RIGHT
  {
    digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      char text[]="RIGHT";
      radio.write(&text, sizeof(text));
      delay(1000);
  }
    if(IR_R==HIGH && IR_L==HIGH) // STOP
  {
      digitalWrite(enable_L,LOW);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,LOW);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      char text[]="STOP";
      radio.write(&text, sizeof(text));
      delay(1000);
  }
    
}
