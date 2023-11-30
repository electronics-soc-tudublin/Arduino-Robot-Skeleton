#include "Driver.h"

Driver::Driver(uint8_t dir_l, uint8_t dir_r, uint8_t pwm_l, uint8_t pwm_r, uint8_t stdby)
  : dir_l (dir_l)
  , dir_r (dir_r)
  , pwm_r (pwm_r)
  , stdby (stdby)
  , motor_l(dir_l, pwm_l)
  , motor_r(dir_r, pwm_r)
{}

void Driver::begin(){
  pinMode(dir_l, OUTPUT);
  pinMode(pwm_l, OUTPUT);

  pinMode(dir_r, OUTPUT);
  pinMode(pwm_r, OUTPUT);

  pinMode(stdby, OUTPUT);
}

void Driver::enable(){
    digitalWrite(stdby, HIGH);
}

void Driver::disable(){
    digitalWrite(stdby, LOW);
}

void Driver::forward(int speed){
  enable();
  motor_l.write(Motor::FORWARD, speed);
  motor_r.write(Motor::FORWARD, speed);
}

void Driver::reverse(int speed){
  enable();
  motor_l.write(Motor::REVERSE, speed);
  motor_r.write(Motor::REVERSE, speed);
}

void Driver::left(int speed){
  enable();
  motor_l.write(Motor::REVERSE, speed);
  motor_r.write(Motor::FORWARD, speed);
}

void Driver::right(int speed){
  enable();
  motor_l.write(Motor::FORWARD, speed);
  motor_r.write(Motor::REVERSE, speed);
}

void Driver::stop(){
  disable();
}
// //
// // void Driver::imu_forward(int speed){
// //   enable();
// //   static float Yaw; //偏航
// //   Serial.println(Yaw);
// //   static float yaw_So = 0;
// //   static uint8_t en = 110;
// //   static unsigned long is_time;
// //   if (en != directionRecord || millis() - is_time > 10)
// //   {
// //     AppMotor.DeviceDriverSet_Motor_control(/*direction_A*/ direction_void, /*speed_A*/ 0,
// //                                            /*direction_B*/ direction_void, /*speed_B*/ 0, /*controlED*/ control_enable); //Motor control
// //     AppMPU6050getdata.MPU6050_dveGetEulerAngles(&Yaw);
// //
// //     is_time = millis();
// //   }
// //    if(en != directionRecord )
// //    {
// //     en = directionRecord;
// //     yaw_So = Yaw;
// //    }
// //
// //   //加入比例常数Kp
// //   int R = (Yaw - yaw_So) * Kp + speed;
// //   if (R > UpperLimit)
// //   {
// //     R = UpperLimit;
// //   }
// //   else if (R < 10)
// //   {
// //     R = 10;
// //   }
// //   int L = (yaw_So - Yaw) * Kp + speed;
// //   if (L > UpperLimit)
// //   {
// //     L = UpperLimit;
// //   }
// //   else if (L < 10)
// //   {
// //     L = 10;
// //   }
// //   motor_l.write(Motor::FORWARD, speed);
// //   motor_r.write(Motor::FORWARD, speed);
// // }
