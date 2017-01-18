#include "main.h"
#include "API.h"
#include "test.h"
//==========================================================-GLOBAL INTERGERS AND FUNCTIONS GO HERE-============================================================
bool special_test = false;
bool special_toggle = true;
bool assist = false;
int left_mem = 0;
int right_mem = 0;
int claw_timeout = 0;
bool claw_thing = 0;
bool test = 0;

void operatorControl() {
	while (1) {
    left_motor_speed = joystickGetAnalog(1, 2);
    right_motor_speed = joystickGetAnalog(1, 3);
		claw_motor_speed = 0;
		claw_timeout++;
		if(joystickGetDigital(1,8, JOY_UP) == 1){
			claw_thing = 1;
		}else if(joystickGetDigital(1,7, JOY_UP) == 1){
			claw_thing = 0;
		}
		if(claw_thing == 1){
			arm_motor_speed = -50;
		}
		if(joystickGetDigital(1,5, JOY_UP) == 1){
			claw_motor_speed = -127;
			claw_timeout = 0;
		}else if(joystickGetDigital(1,5, JOY_DOWN) == 1){
			if(claw_timeout < 100){
				claw_motor_speed = 127;
			}else{
				claw_motor_speed = 60;
			}
		}else{
				claw_timeout = 0;
		}
		arm_motor_speed = 0;
		if(joystickGetDigital(1,6, JOY_UP) == 1){
			arm_motor_speed = 127;
			if(assist == true){
				assist_piston = 1;
			}else if(assist == false){
				assist_piston = 0;
			}
			left_mem = analogRead(arm_pot_a);
		}else if(joystickGetDigital(1,6, JOY_DOWN) == 1){
			arm_motor_speed = -127;
			assist_piston = 0;
			left_mem = analogRead(arm_pot_a);
		}
		if(joystickGetDigital(1,5, JOY_UP) == 1){
		}else if(joystickGetDigital(1,5, JOY_DOWN) == 1){
		}
		update_hardware();
	}
}
