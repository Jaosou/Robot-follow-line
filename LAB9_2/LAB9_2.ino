#define PWM_M1 D2
#define in1_M1 D3
#define in2_M1 D4
#define in1_M2 D5
#define in2_M2 D6
#define PWM_M2 D7
#include <Servo.h>
#include <Ultrasonic.h>
Ultrasonic ultrasonic(D9,D10);

Servo myservo;
int degree;
int readdegree;

#define IRsensorL D1
#define IRsensorR D0
int LsensorValue;
int RsensorValue;

int distanceCM;
int distanceINC;
int speed = 143;


void setup() {
  myservo.attach(D8);
  pinMode(PWM_M1,OUTPUT);
  pinMode(in1_M1,OUTPUT);
  pinMode(in2_M1,OUTPUT);
  pinMode(PWM_M2,OUTPUT);
  pinMode(in1_M2,OUTPUT);
  pinMode(in2_M2,OUTPUT);
}

void move(int LsenValue,int RsenValue){
  if(LsenValue == 1 && RsenValue == 0){
    turnLeft(); 
  }else if (LsenValue == 0 && RsenValue == 1){
    turnRigth();                 
  }else if(LsenValue == 1 && RsenValue == 1){
    stop();
  }else if(LsenValue == 0 && RsenValue == 0){
    forward();
  }
}

void loop() {
  delay(10);
  LsensorValue = digitalRead(IRsensorL);
  RsensorValue = digitalRead(IRsensorR);
  distanceCM = ultrasonic.read(CM);
  if (distanceCM <= 8){
    stop();
    myservo.write(180);
    delay(300);
    myservo.write(0);
    delay(300);
  }else{
    /* forward(); */
    move(LsensorValue,RsensorValue);
  }
  // put your main code here, to run repeatedly:
}

void turnLeft(){
  digitalWrite(in1_M1,LOW);
  digitalWrite(in2_M1,HIGH);
  analogWrite(PWM_M1,speed);

  digitalWrite(in1_M2,LOW);
  digitalWrite(in2_M2,HIGH);
  analogWrite(PWM_M2,speed);
}

void forward(){
  digitalWrite(in1_M1,HIGH);
  digitalWrite(in2_M1,LOW);
  analogWrite(PWM_M1,speed);

  digitalWrite(in1_M2,LOW);
  digitalWrite(in2_M2,HIGH);
  analogWrite(PWM_M2,speed);
}

void stop(){
  digitalWrite(in1_M1,LOW);
  digitalWrite(in2_M1,LOW);
  analogWrite(PWM_M1,0);
  

  digitalWrite(in1_M2,LOW);
  digitalWrite(in2_M2,LOW);
  analogWrite(PWM_M2,0);
}

void turnRigth(){
  digitalWrite(in1_M1,HIGH);
  digitalWrite(in2_M1,LOW);
  analogWrite(PWM_M1,speed);

  digitalWrite(in1_M2,HIGH);
  digitalWrite(in2_M2,LOW);
  analogWrite(PWM_M2,speed);
}