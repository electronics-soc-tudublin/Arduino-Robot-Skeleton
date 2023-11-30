#ifndef ELEC_SOC_MOTOR
#define ELEC_SOC_MOTOR
#include "Arduino.h"

class Motor{
  public:
    enum Direction{
      FORWARD,
      REVERSE
    };

    Motor(uint8_t pin1, uint8_t pwm);
    void write(Direction dir, uint8_t pwm);
  private:
    uint8_t pin1;
    uint8_t pwm;
};

#endif // ELEC_SOC_MOTOR
