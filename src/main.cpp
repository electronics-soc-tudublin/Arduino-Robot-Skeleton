#include <Arduino.h>

#include <Driver.h>
#include <NewPing.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

NewPing ping(13, 12);
Driver driver;
Adafruit_MPU6050 mpu;

#define RUN_BUTTON 2
#define SAMPLE_PERIOD 10
#define NUM_AVERAGE 100

float gyro_off;
sensors_event_t a, g, temp;

float delta_z = 0;
float yaw = 0;

unsigned long now;
unsigned long last_time;

void setup() {
  while(digitalRead(RUN_BUTTON));
  Serial.begin(115200);
  Serial.println("Starting gyro app");

  if(!mpu.begin()){
    Serial.println("Error in initializing MPU6050. Check wiring");
    while(1);
  }
  Serial.println("MPU6050 initialized");
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_44_HZ);

  float gyro_off_accumulate;
  Serial.println("Calibrating");
  for (int i = 0; i < NUM_AVERAGE; i++){
    mpu.getEvent(&a, &g, &temp);
    gyro_off_accumulate += g.gyro.z;
  }
  gyro_off = gyro_off_accumulate/NUM_AVERAGE;
  Serial.print("Calibration complete. Offset value: ");
  Serial.print(gyro_off);
  Serial.println();
  driver.begin();
  driver.enable();
  last_time = millis();
}

void loop() {

  if (millis() - last_time >= SAMPLE_PERIOD){
    mpu.getEvent(&a, &g, &temp);
    auto gz = g.gyro.z;
    yaw += (gz - gyro_off) * (millis() - last_time)/1000.0f;
    last_time = millis();
  }

  Serial.print("Yaw(rad): ");
  Serial.print(yaw);
  Serial.print(';');
  Serial.print("Yaw(deg): ");
  Serial.print(yaw * RAD_TO_DEG);
  Serial.print(';');
  Serial.println();

  if (yaw*RAD_TO_DEG < -5){
    driver.right(100);
  }
  else if (yaw*RAD_TO_DEG > 5){
    driver.left(100);
  }
  else
  {
    driver.disable();
  }


  delay(SAMPLE_PERIOD);
}
