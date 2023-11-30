#include "Driver.h"

Driver::Driver(uint8_t dir_l, uint8_t dir_r, uint8_t pwm_l, uint8_t pwm_r, uint8_t stdby)
  : dir_l {dir_l}
  , dir_r {dir_r}
  , pwm_r {pwm_r}
  , stdby {stdby}
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
