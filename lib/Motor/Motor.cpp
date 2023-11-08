#include "Motor.h"

Motor::Motor(uint8_t pin1, uint8_t pwm){
  this->pin1 = pin1;
  this->pwm = pwm;
  pinMode(pin1, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void Motor::write(Direction dir, uint8_t power){
  switch (dir)
  {
  case FORWARD:
    digitalWrite(pin1, HIGH);
    break;

  case REVERSE:
    digitalWrite(pin1, LOW);
    break;

  default:
    break;
  }
  analogWrite(pwm, power);
}
