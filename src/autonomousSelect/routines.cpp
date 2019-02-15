#include "main.h"
#include "autonomousSelect/autonomousRoutine.hpp"
#include "autonomousSelect/routines.hpp"
#include "autonomousSelect/screen.hpp"
#include "robot.hpp"
#include <vector>

void disableAuton(){}

void disabledPrint(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red, true);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red, true);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue, true);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue, true);

  drawLines(parent);

  defaultLeftCaps(parent);
  defaultRightCaps(parent);

  defaultLeftFlags(parent);
  defaultMiddleFlags(parent);
  defaultRightFlags(parent);
  drawFlagPoles(parent);

  defaultParking(parent);

  defaultLeftBalls(parent);
  defaultRightBalls(parent);
}

autonomousRoutine disable("Disable - 0S", &white_text, disableAuton, disabledPrint);

void redFlag1Auton(){
  okapi::AsyncMotionProfileController profileController = okapi::AsyncControllerFactory::motionProfile(
    1.0,  // Maximum linear velocity of the Chassis in m/s
    2.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.7_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {1.7_ft, 0_in, 0_deg}}, "B");

  robot::intake.moveVoltage(12000);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);

  while(robot::catapultLimit.isPressed()){
    pros::delay(10);
  }
  robot::catapult.tarePosition();

  robot::catapult.moveAbsolute(robot::primedCatapultPosition, 200);

  profileController.setTarget("A", true);
  profileController.waitUntilSettled();

  robot::chassis.turnAngle(-90_deg);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);

  while(!robot::catapultLimit.isPressed()){
    pros::delay(10);
  }

  robot::catapult.moveVelocity(0);

  profileController.setTarget("A");
  profileController.waitUntilSettled();
}

void redFlag1Print(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red, true);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue);

  drawLines(parent);

  cap blue_cap_1(parent, cap_position::left_1, cap_state::blue);
  cap red_cap_2(parent, cap_position::left_2, cap_state::red_slanted);
  cap red_cap_3(parent, cap_position::left_3, cap_state::red, true);
  cap blue_cap_4(parent, cap_position::left_4, cap_state::blue);

  defaultRightCaps(parent);


  flag left_top(parent, flag_position::left_high, flag_state::red, true);
  flag left_mid(parent, flag_position::left_middle, flag_state::red, true);
  flag left_low(parent, flag_position::left_low, flag_state::red, true);

  defaultMiddleFlags(parent);
  defaultRightFlags(parent);
  drawFlagPoles(parent);

  defaultParking(parent);

  defaultLeftBalls(parent);
  defaultRightBalls(parent);
}

autonomousRoutine redFlag1("Red Flag - 11S", &red_text, redFlag1Auton, redFlag1Print);


std::vector<autonomousRoutine> autonomousRoutines = {disable, redFlag1};
