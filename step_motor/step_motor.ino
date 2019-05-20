#include<Stepper.h>
int motor_rev=32;
int motor_output=4096;
Stepper small_stepper(motor_rev,8,9,10,11);
int steps;
void setup() {

}

void loop() {
  steps = motor_output;
  small_stepper.step(steps);
  delay(1000);

  steps = -motor_output;
  small_stepper.step(steps);
  delay(1000);
}
