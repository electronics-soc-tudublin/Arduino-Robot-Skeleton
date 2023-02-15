#ifndef MOVEMENT
#define MOVEMENT


// I think there should be 2 pins for each direcrtion. Is onw of them tied to a fixed voltage?
#define RIGHT_SPEED 5     //Pin 5 changes speed on the right motors ,range from 0 to 255
#define RIGHT_DIRECTION 7 //Pin 7 changes direction of right motors, High or Low
#define LEFT_SPEED 6      //changes speed on the left motors ,range from 0 to 255
#define LEFT_DIRECTION 8  //changes direction of left motors, High or Low
#define STANDBY_PIN 3      //controls all motors, always set High

#define TURN_DELAY 265
class Movement{
public:
    Movement();
    void start();
    void stop();
    void brake();
    void forward(int pwm);
    void reverse(int pwm);
    void turnLeft(int pwm, int angle);
    void turnRight(int pwm, int angle);
    void initMotors();
private:

};
#endif
