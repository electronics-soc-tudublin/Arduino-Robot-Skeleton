#include "Movement.h"
#include "Arduino.h"
#include "Servo.h"

Movement::Movement(){
    
}

/*
For starting the robot
*/
void Movement::start() {
    //Set direction forward
    digitalWrite(RIGHT_DIRECTION, HIGH);
    digitalWrite(LEFT_DIRECTION, HIGH);
    //Set speed to 0
    analogWrite(RIGHT_SPEED, 0);
    analogWrite(LEFT_SPEED, 0);
    //Enable motor driver
    digitalWrite(STANDBY_PIN, HIGH);
}

/**
 * Stops the motors by disconnecting them from power
 * The motors will gradually come to a stop
 * */
void Movement::stop(){
    //Set the direction forward
    digitalWrite(LEFT_DIRECTION, LOW);
    digitalWrite(RIGHT_DIRECTION, LOW);
    //Set the speed
    analogWrite(RIGHT_SPEED, 0);
    analogWrite(LEFT_SPEED, 0);
}

/**
 * Stops the motors by shorting their wires together
 * The motor will stop instantly
 * */
void Movement::brake(){
    //Set the direction forward
    digitalWrite(LEFT_DIRECTION, HIGH);
    digitalWrite(RIGHT_DIRECTION, HIGH);
    //Set the speed
    analogWrite(RIGHT_SPEED, 0);
    analogWrite(LEFT_SPEED, 0);
}

/**
 * Drives forward in a straight line
 * @param pwm The speed of the motor (0 - 255)
 * */
void Movement::forward(int pwm){
    //Set the direction forward
    digitalWrite(LEFT_DIRECTION, HIGH);
    digitalWrite(RIGHT_DIRECTION, HIGH);
    //Set the speed
    analogWrite(RIGHT_SPEED, pwm-30);
    analogWrite(LEFT_SPEED, pwm);
}

/**
 * Drives backwards in a straight line
 * @param pwm The speed of the motors (0 - 255)
 * */
void Movement::reverse(int pwm){
    //Set the direction forward
    digitalWrite(LEFT_DIRECTION, LOW);
    digitalWrite(RIGHT_DIRECTION, LOW);
    //Set the speed
    analogWrite(RIGHT_SPEED, pwm);
    analogWrite(LEFT_SPEED, pwm);
}

/**
 * Turns left. If no angle is given 90 deg is assumed
 * @param pwm The speed of the motors
 * @param angle The turning angle in degrees
 * */
void Movement::turnLeft(int pwm = 255, int angle = 1000){
    //pwm = 127;
     //Set the direction forward
    digitalWrite(LEFT_DIRECTION, LOW);
    digitalWrite(RIGHT_DIRECTION, HIGH);
    //If the angle is not set, just use a delay
    if (angle == 1000){
        analogWrite(RIGHT_SPEED, pwm);
        analogWrite(LEFT_SPEED, pwm);
        delay(TURN_DELAY);
        return;
    } else{
        //IMU STUFF  
    }
}

void Movement::turnRight(int pwm = 255, int angle = 1000){
    //pwm = 127;
     //Set the direction forward
    digitalWrite(LEFT_DIRECTION, HIGH);
    digitalWrite(RIGHT_DIRECTION, LOW);
    //If the angle is not set, just use a delay
    if (angle == 1000){
        analogWrite(RIGHT_SPEED, pwm);
        analogWrite(LEFT_SPEED, pwm);
        delay(TURN_DELAY);
    } else{
        //IMU STUFF  
    }
}

// setup executes each line of code once
void Movement::initMotors() {
    //Initilie the motor outputs

    //Initiaize the senors
    //Blink a statu LED
    pinMode(RIGHT_SPEED, OUTPUT);
    pinMode(RIGHT_DIRECTION, OUTPUT);
    pinMode(LEFT_SPEED, OUTPUT);
    pinMode(LEFT_DIRECTION, OUTPUT);
    pinMode(STANDBY_PIN, OUTPUT);
}