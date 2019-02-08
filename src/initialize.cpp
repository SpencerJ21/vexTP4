#include "main.h"
#include "robot.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize(){
  robot::catapult.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  robot::catapult.setGearing(okapi::AbstractMotor::gearset::green);
  robot::catapult.setEncoderUnits(okapi::AbstractMotor::encoderUnits::rotations);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
