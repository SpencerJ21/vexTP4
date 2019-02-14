#include "main.h"
#include "robot.hpp"
#include <vector>
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

int selection = 0;

void competition_initialize() {
  robot::screen::state = screenMode::selection;
}
