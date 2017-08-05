#include <Stepper.h>

const int stepsPerRevolution = 100;  //this is to fit the number of steps per revolutio for your motor
 
int In1Port = 8;
int In2Port = 9;
int In3Port = 10;
int In4Port = 11;

Stepper myStepper(stepsPerRevolution, In1Port, In3Port, In2Port, In4Port);

void setup() {
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
