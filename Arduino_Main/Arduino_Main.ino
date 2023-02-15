#include "Movement.h"
#include <Servo.h>
#include <NewPing.h>
#include <string.h>

#define FORWARD_HEADING 90
#define RIGHT_HEADING 0
#define LEFT_HEADING 180
#define THRESHOLD 30
#define SPEED 127

Movement robot;
NewPing ultraSonic(13, 12, 400);
Servo servo;
String string;

/**
* @return Returns true if there is an obstruction below the threshold
*/
bool checkSensor(int threshold) {
    int dist = ultraSonic.ping_cm();
    Serial.print("Distance(cm): ");
    Serial.println(dist);
    Serial.flush();
    servo.write(90);
    delay(250);
    return ( (dist <= threshold) && (dist != 0) );
}

/**
 * Checks the ultrasonic sensor for an obstacle at heading angle
 * @return false if no obstacle
 * */
bool checkObstacle(int heading, int threshold) {
    servo.write(heading);
    delay(250); // delay for movement
    return checkSensor(threshold);
}

void setup(){
    Serial.begin(9600);
    servo.attach(10);

    servo.write(90);
    
    // // Tests
    robot.start();

    //TEST MOVEMENT
    // robot.forward(255);
    // delay(1000);
    // robot.stop();
    // delay(500);

    // robot.reverse(255);
    // delay(1000);
    // robot.stop();
    // delay(500);

    // robot.turnLeft(255); // This is a blocking function
    // robot.stop();
    // delay(500);

    // robot.turnRight(255); // This is a blocking function
    // robot.stop();
    // delay(500);
    // while(1);
}

bool RUN = true;

void loop() {
    // Serial.print("Left: "); // left
    // Serial.println(checkObstacle(0, 20));
    // Serial.print("Forward: "); //forward
    // Serial.println(checkObstacle(90, 20));
    // Serial.print("Right "); // right
    // Serial.println(checkObstacle(180, 20));


    if (RUN) {
        int degSum = 0;

        // Check if the path is clear
        if (!checkSensor(THRESHOLD))
        {
            robot.forward(SPEED);
        }
        else {
            robot.brake();
            // Check if I can turn right
            if (!checkObstacle(RIGHT_HEADING, THRESHOLD))
            {
                robot.turnRight(SPEED);
                robot.forward(SPEED);
                degSum += 90;
            } else if (!checkObstacle(LEFT_HEADING, THRESHOLD))
            {
                robot.turnLeft(SPEED);
                robot.forward(SPEED);
                degSum -= 90;
            } else
            {
                robot.turnRight(SPEED);
                robot.turnRight(SPEED);
                robot.forward(SPEED);
                degSum += 180;
            }
        }
    }
}

/*
while “in maze”
    counter = 1
    while counter != 0
        counter = 0
        if you can go forward
            go forward
        if you can turn right
            counter += 90
            you turn right
        if you can turn left
            counter -= 90
            you turn left
        else
            go back
*/
