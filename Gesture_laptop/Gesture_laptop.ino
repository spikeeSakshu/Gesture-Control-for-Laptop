/* Developed by Spikee */ 
#include "Keyboard.h"
#include <Keyboard.h>
#include <HID.h>

//Ultrasonic sensor1
int trigPin1 = 2;
int echoPin1 = 3;

//Ultrasonic Sensor2
int trigPin2 = 4;
int echoPin2 = 5;

long duration1, cm1;
long duration2, cm2;
int value1;
int value2;
void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop(){
digitalWrite(trigPin1, LOW);
delayMicroseconds(5);//set according to ur choice
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
pinMode(echoPin1, INPUT);
duration1 = pulseIn(echoPin1, HIGH);// convert the time into a distance
cm1 = (duration1/2) / 29.1;
digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
pinMode(echoPin2, INPUT);
duration2 = pulseIn(echoPin2, HIGH);
cm2 = (duration2/2) / 29.1;
delay(300);

Serial.println(cm1);
Serial.println(cm2);
  if (cm1 < 10){
    value1 = 1;
    delay(100);
  }
  if (cm2 < 10 && value1 == 1){
    value1 = 0;
    goLeft();
    delay(500);
  }
  if (cm2 < 10){
    value2 = 1;
    delay(100);
  }
  if (cm1 < 10 && value2 == 1){
    value2 = 0;
    goRight();
    delay(500);
  }
}

void goLeft(){
  Serial.println("Left ultrasonic sensor");
  Keyboard.print("Spikee Rocks");
  Keyboard.write(KEY_RETURN);
    delay(200);
}

void goRight(){
  Serial.println("Right ultrasonic sensor");
  Keyboard.print("yoo");
  Keyboard.write(KEY_RETURN);
    delay(200);  
}
