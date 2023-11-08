#include <Arduino.h>
#include <Servo.h>
#include <Driver.h>

constexpr uint8_t speed = 150;

Servo servo1;
Driver driver;

void forward(int speed){
  driver.enable();
  driver.motor_l.write(Motor::FORWARD, speed);
  driver.motor_r.write(Motor::FORWARD, speed);
}

void reverse(int speed){
  driver.enable();
  driver.motor_l.write(Motor::REVERSE, speed);
  driver.motor_r.write(Motor::REVERSE, speed);
}

void left(int speed){
  driver.enable();
  driver.motor_l.write(Motor::REVERSE, speed);
  driver.motor_r.write(Motor::FORWARD, speed);
}

void right(int speed){
  driver.enable();
  driver.motor_l.write(Motor::FORWARD, speed);
  driver.motor_r.write(Motor::REVERSE, speed);
}
void stop(){
  driver.disable();
}

int a0;
int a1;
int a2;

char buff[265];

void setup() {
  driver.begin();
  driver.enable();
  Serial.begin(115200);
}

void loop() {
  a0 = analogRead(A0);
  a1 = analogRead(A1);
  a2 = analogRead(A2);

  // a0 = digitalRead(A0);
  // a1 = digitalRead(A1);
  // a2 = digitalRead(A2);

  if(a0 > 650){
    forward(speed);
  }
  else if(a1 > 650){
    left(speed);
  }
  else if(a2 > 650){
    right(speed);
  }

  sprintf(buff, "/*%d;%d;%d*/\n", a0, a1, a2);
  Serial.print(buff);
  delay(10);
}
