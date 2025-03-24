#define BLYNK_TEMPLATE_ID           "TMPL6sBemWReF"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "4RUsTWGhLPeQUgNyPTai1FjQqORp6xcA"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo myservo;
int degree;
int readdegree;

char ssid[] = "Jaosou";
char pass[] = "30082022";

void setup() {
  myservo.attach(D8);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  readdegree = myservo.read();
  Blynk.virtualWrite(V0,readdegree);
  delay(500);
}

BLYNK_WRITE(V1){
  degree = param.asInt();
  myservo.write(degree);
}