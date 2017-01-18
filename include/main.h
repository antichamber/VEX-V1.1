#ifndef MAIN_H_
#define MAIN_H_
#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif
#define piston_a 2
#define piston_b 3
#define left_quad_top 4
#define left_quad_bottom 5
#define right_quad_top 6
#define right_quad_bottom 7
#define leda = 8
#define ledb = 9
#define ledc = 10
#define button_enter 11
#define button_select 12
#define left_motor_a 10
#define left_motor_b 8
#define right_motor_a 1
#define right_motor_b 3
#define arm_motor_a 9
#define arm_motor_b 2
#define arm_motor_c 5
#define arm_motor_d 6
#define claw_motor_a 7
#define claw_motor_b 4
#define arm_pot_a 1
#define arm_pot_b 2
#define arm_adjust_a 100
#define claw_adjust_a 100
#define claw_adjust_b 50

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif
#endif
