#include <Arduino.h>

#include <Driver.h>
#include <NewPing.h>
#include <Adafruit_MPU6050.h>

NewPing ping(13, 12);
Driver driver;

#define RUN_BUTTON 2

void setup() {
  while(digitalRead(RUN_BUTTON));
  Serial.begin(115200);
  Serial.println("Starting gyro app");

  // driver.begin();
  // driver.enable();
}

void loop() {
}
