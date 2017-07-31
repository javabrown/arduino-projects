#include <Stepper.h>

int in1Pin = 2;
int in2Pin = 3;
int in3Pin = 4;
int in4Pin = 5;

Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);

void setup()
{
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);

    motor.setSpeed(25);
}

void loop()
{
    int steps = 360;
    motor.step(steps);
    delay(100);

    steps = -360;
    motor.step(steps);
    delay(100);
}
