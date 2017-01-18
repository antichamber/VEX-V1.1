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
#define left_motor_a 
#define left_motor_b 
#define left_motor_c 
#define right_motor_a 
#define right_motor_b 
#define right_motor_c
#define arm_motor_a 
#define arm_motor_b 
#define arm_motor_c 
#define arm_motor_d 
#define claw_motor_a 
#define claw_motor_b 
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

