#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

int In1Port = 8;
int In2Port = 9;
int In3Port = 10;
int In4Port = 11;

Stepper stepper(STEPS_PER_MOTOR_REVOLUTION, In1Port, In3Port, In2Port, In4Port);
 
int  steps2Take;

void setup(){ 
}

void loop() {
  steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION ;  // Rotate CW 1 turn
  stepper.setSpeed(500);
  stepper.step(steps2Take);
  delay(1000);
  
  steps2Take  =  - STEPS_PER_OUTPUT_REVOLUTION;  // Rotate CCW 1 turn  
  stepper.setSpeed(500);  // 700 a good max speed??
  stepper.step(steps2Take);
  delay(2000);
}
