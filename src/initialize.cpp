#include "main.h"
#include "robot.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
extern void screenControllerFN(void* param);

void initialize(){
  robot::screen::controller = new pros::Task(screenControllerFN,
                                                           NULL,
                                          TASK_PRIORITY_DEFAULT,
                                       TASK_STACK_DEPTH_DEFAULT,
                                                       "Screen");
  robot::screen::state = screenMode::notification;
/*
  while(!robot::catapultLimit.isPressed()){
    robot::screen::notification = "Warning - catapult limit should start pressed. Check for faulty switch.";
  }
*/
  robot::screen::notification = "Epic Gamer moment";

  robot::screen::state = screenMode::sans;
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  robot::screen::state = screenMode::sans;
}
