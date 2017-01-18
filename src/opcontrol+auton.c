#include "main.h"
#include "API.h"
#include "test.h"
//==========================================================-GLOBAL INTERGERS AND FUNCTIONS GO HERE-============================================================
bool special_test = false;
bool special_toggle = true;
bool assist = false;
bool assist_toggle_ = false;
int left_mem = 0;
int right_mem = 0;
bool test = 0;

void autonomous() {

}

void operatorControl() {
	while (1) {
    left_motor_speed = joystickGetAnalog(1, 2);
    right_motor_speed = joystickGetAnalog(1, 3);
		if(joystickGetDigital(1,5, JOY_UP) == 1){
			claw_piston = 0;
		}else if(joystickGetDigital(1,5, JOY_UP) == 1){
			claw_piston = 1;
		}

		if(joystickGetDigital(1,6, JOY_UP) == 1){
			arm_motor_speed = 127;
			if(assist_toggle_ == true){
				assist = 1;
			}
		}else if(joystickGetDigital(1,6, JOY_UP) == 1){
			arm_motor_speed = -127;
			assist = 0;
		}else{
			arm_motor_speed = 0;
			assist = 0;
		}

		if(joystickGetDigital(1,8, JOY_LEFT) == 1){
			assist_toggle_ = true;
		}else if(joystickGetDigital(1,8, JOY_DOWN) == 1){
			assist_toggle_ = false;
		}
	}
}
