#include "main.h"
const unsigned int scaler[130] = {0,0,0,0,10,10,10,11,11,11,11,11,11,11,12,12,13,13,13,14,14,14,14,14,15,15,16,16,16,17,17,17,18,18,19,19,19,19,20,20,20,21,21,21,21,
22,22,23,24,24,25,25,24,25,26,26,26,26,28,28,98,29,29,29,30,30,31,32,32,32,33,33,34,35,36,36,36,36,38,39,39,39,39,42,45,45,46,46,47,47,49,49,50,50,50,
52,52,54,57,57,59,61,61,64,64,64,66,66,72,72,77,79,81,83,85,87,91,95,101,111,111,124,124,124,125,127,127,127,127};
int left_motor_speed = 0;
int right_motor_speed = 0;
int arm_motor_speed = 0;
int temp_a = 0;
int temp_b = 0;

bool assist_piston = false;        //used to store the state of the assist piston3
bool assist_toggle = true;         //used to keep track of if the pistons has been properly instructed
bool claw_piston = false;        //used to store the state of the claw pistons
bool claw_toggle = true;         //used to keep track of if the pistons has been properly instructed

int motor_arm_slew = 0;
int motor_left_slew = 0;
int motor_right_slew = 0;

void slew_motor_task(){
  if(motor_arm_slew - arm_motor_speed >= 5){
    motor_arm_slew -= 5;
  }else if(motor_arm_slew - arm_motor_speed <= -5){
    motor_arm_slew += 5;
  }else{
    motor_arm_slew = arm_motor_speed;
  }

  if(motor_left_slew - left_motor_speed >= 5){
    motor_left_slew -= 5;
  }else if(motor_left_slew - left_motor_speed <= -5){
    motor_left_slew += 5;
  }else{
    motor_left_slew = left_motor_speed;
  }

  if(motor_right_slew - right_motor_speed >= 5){
    motor_right_slew -= 5;
  }else if(motor_right_slew - right_motor_speed <= -5){
    motor_right_slew += 5;
  }else{
    motor_right_slew = right_motor_speed;
  }
}


void update_hardware(){
  slew_motor_task();
  if(assist_piston == 0 && assist_toggle == 1){
    digitalWrite(assist_piston_pin, LOW);
    assist_toggle = 0;
  }else if(assist_piston == 1 && assist_toggle == 0){
    digitalWrite(assist_piston_pin, HIGH);
    assist_toggle = 1;
  }
  if(claw_piston == 0 && claw_toggle == 1){
    digitalWrite(claw_piston_pin, LOW);
    claw_toggle = 0;
  }else if(claw_piston == 1 && claw_toggle == 0){
    digitalWrite(claw_piston_pin, HIGH);
    claw_toggle = 1;
  }                                //used to set all pneuamatics and motors to their proper speed/position
  if(motor_left_slew < 0){                                             //asking for a negitive number from the scaler will break the program, so this inserts a double negitive if nessisary
    motorSet(left_motor_a, 0 - scaler[0 - motor_left_slew]);            //this assigns the arm motors arm speed
    motorSet(left_motor_b, 0 - scaler[0 - motor_left_slew]);
    motorSet(left_motor_c, 0 - scaler[0 - motor_left_slew]);
  }else{
    motorSet(left_motor_a, 0 - scaler[0 - motor_left_slew]);
    motorSet(left_motor_b, 0 - scaler[0 - motor_left_slew]);
    motorSet(left_motor_c, 0 - scaler[0 - motor_left_slew]);
  }
  if(motor_right_slew < 0){                                             //asking for a negitive number from the scaler will break the program, so this inserts a double negitive if nessisary
    motorSet(right_motor_a, 0 - scaler[0 - motor_right_slew]);            //this assigns the arm motors arm speed
    motorSet(right_motor_b, 0 - scaler[0 - motor_right_slew]);
    motorSet(right_motor_c, 0 - scaler[0 - motor_right_slew]);
  }else{
    motorSet(right_motor_a, scaler[motor_right_slew]);
    motorSet(right_motor_b, scaler[motor_right_slew]);
    motorSet(right_motor_c, scaler[motor_right_slew]);
  }
  if(motor_arm_slew < 0){                                             //asking for a negitive number from the scaler will break the program, so this inserts a double negitive if nessisary
    motorSet(arm_motor_a, 0 - scaler[0 - motor_arm_slew]);            //this assigns the arm motors arm speed
    motorSet(arm_motor_b, 0 - scaler[0 - motor_arm_slew]);
    motorSet(arm_motor_c, 0 - scaler[0 - motor_arm_slew]);
    motorSet(arm_motor_d, 0 - scaler[0 - motor_arm_slew]);
  }else{
    motorSet(arm_motor_a, scaler[motor_arm_slew]);
    motorSet(arm_motor_b, scaler[motor_arm_slew]);
    motorSet(arm_motor_c, scaler[motor_arm_slew]);
    motorSet(arm_motor_d, scaler[motor_arm_slew]);
  }
}
