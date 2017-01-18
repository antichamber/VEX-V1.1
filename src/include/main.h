#ifndef MAIN_H_
#define MAIN_H_
#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif
#define claw_piston_pin 2
#define assist_piston_pin 3
#define left_motor_a 1
#define left_motor_b 2
#define left_motor_c 3
#define right_motor_a 8
#define right_motor_b 9
#define right_motor_c 10
#define arm_motor_a 4
#define arm_motor_b 5
#define arm_motor_c 6
#define arm_motor_d 7

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif
#endif
