#include "main.h"

void autonomous() {
  motorSet(claw_motor_a, -127);
  motorSet(claw_motor_a, -127);
  delay(500);
  motorSet(claw_motor_a, 0);
  motorSet(claw_motor_a, 0);
}
