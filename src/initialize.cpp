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
  robot::catapult.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  robot::catapult.setGearing(okapi::AbstractMotor::gearset::green);
  robot::catapult.setEncoderUnits(okapi::AbstractMotor::encoderUnits::rotations);

  robot::scraper.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  robot::scraper.setGearing(okapi::AbstractMotor::gearset::green);
  robot::scraper.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);

  robot::chassis.setMaxVelocity(200);
  robot::chassis.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);

  robot::screen::controller = new pros::Task(screenControllerFN,
                                                           NULL,
                                          TASK_PRIORITY_DEFAULT,
                                       TASK_STACK_DEPTH_DEFAULT,
                                                       "Screen");
  robot::screen::state = screenMode::notification;

  //while(!robot::catapultLimit.isPressed() && pros::competition::is_connected()){
  //  robot::screen::notification = "Warning - catapult limit should start pressed. Check for faulty switch.";
  //  pros::delay(10);
  //}

  //while(robot::catapultLimit.isPressed() && pros::competition::is_connected()){
  //  robot::screen::notification = "Draw catapult to verify limit switch is functioning";
  //  pros::delay(10);
  //}

  robot::screen::notification = "All Systems Ready";

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  robot::screen::state = screenMode::sans;
}
