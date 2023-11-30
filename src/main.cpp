#include <Arduino.h>
#include <Servo.h>
#include "Driver.h"
#include <NewPing.h>


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

int ir_l;
int ir_m;
int ir_r;

int pin_ir_l = A0;
int pin_ir_m = A1;
int pin_ir_r = A2;

char buff[265];

int samples[2];
// Trigger pin 13, Echo pin 12
NewPing ping(13, 12);
int btn_pin = 2;

void setup() {
  driver.begin();
  driver.enable();
  Serial.begin(115000);

  while(digitalRead(btn_pin));
  forward(127);
}

void loop() {
  ir_m = analogRead(pin_ir_m);

  if(ir_m > 100){
    sprintf(buff, "DETECTED: %d", ir_m);
    digitalWrite(13, HIGH);
    driver.disable();
    // Delay to account for the robots momentum
    delay(300);
  }
  else
  {
    sprintf(buff, "NOT: %d", ir_m);
    digitalWrite(13, LOW);
    driver.enable();
  }

  Serial.println(buff);
  delay(10);
}
