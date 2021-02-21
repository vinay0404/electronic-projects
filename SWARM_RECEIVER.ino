
const int enable_L = 7;
const int enable_R = 6;
const int MotorLeft_A = 5;
const int MotorLeft_B = 4;
const int MotorRight_A = 2;
const int MotorRight_B = 3;



#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CNS, CE
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
   pinMode(enable_L,OUTPUT);
    pinMode(enable_R,OUTPUT);
    pinMode(MotorLeft_A,OUTPUT);
    pinMode(MotorLeft_B,OUTPUT);
    pinMode(MotorRight_A,OUTPUT);
    pinMode(MotorRight_B,OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}


void loop() 
{
      char text[32] = "";
      char cond;
  if (radio.available()) 
  {

    radio.read(&text, sizeof(text));
    Serial.println(text);
 }
        if(text[0]=='F')//FORWARD
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      Serial.println("FRWD");
    }
    if(text[0]=='L')//LEFT TURN
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,HIGH);
      digitalWrite(MotorLeft_B,LOW);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,LOW);
      digitalWrite(MotorRight_B,HIGH);
      delay(200);
    }
   if(text[0]=='R')//RIGHT
    {
      digitalWrite(enable_L,HIGH);
      digitalWrite(MotorLeft_A,LOW);
      digitalWrite(MotorLeft_B,HIGH);
      digitalWrite(enable_R,HIGH);
      digitalWrite(MotorRight_A,HIGH);
      digitalWrite(MotorRight_B,LOW);
      delay(200);
    }
      if(text[0]=='S')//STOP
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
