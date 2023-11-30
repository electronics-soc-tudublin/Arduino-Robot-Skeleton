#ifndef ELEC_SOC_DRIVER
#define ELEC_SOC_DRIVER
#include "Arduino.h"
#include "Motor.h"

class Driver{
  public:
    Driver(uint8_t dir_l=7, uint8_t dir_r=8, uint8_t pwm_l=5, uint8_t pwm_r=6, uint8_t stdby=3);
    void begin();
    void enable();
    void disable();

    Motor motor_l;
    Motor motor_r;

  private:
    uint8_t dir_l;
    uint8_t pwm_l;

    uint8_t dir_r;
    uint8_t pwm_r;

    uint8_t stdby;
};

#endif // ELEC_SOC_DRIVER
