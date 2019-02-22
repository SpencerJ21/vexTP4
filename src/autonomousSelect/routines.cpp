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
    0.9,  // Maximum linear velocity of the Chassis in m/s
    1.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.8_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {2_ft, 2_in, 0_deg}}, "B");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {4_ft, 6_in, 0_deg}}, "C");

  robot::scraper.moveAbsolute(30, 50);
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

  robot::scraper.moveAbsolute(0, 50);
  robot::chassis.turnAngle(-90_deg);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  robot::intake.moveVoltage(0);
  robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);

  while(!robot::catapultLimit.isPressed()){
    pros::delay(10);
  }

  robot::catapult.moveVelocity(0);

  profileController.setTarget("C");
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

void blueFlag1Auton(){
  okapi::AsyncMotionProfileController profileController = okapi::AsyncControllerFactory::motionProfile(
    0.9,  // Maximum linear velocity of the Chassis in m/s
    1.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.8_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {2_ft, -2_in, 0_deg}}, "B");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {4_ft, -6_in, 0_deg}}, "C");

  robot::scraper.moveAbsolute(30, 50);
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

  robot::scraper.moveAbsolute(0, 50);
  robot::chassis.turnAngle(90_deg);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  robot::intake.moveVoltage(0);
  robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);

  while(!robot::catapultLimit.isPressed()){
    pros::delay(10);
  }

  robot::catapult.moveVelocity(0);

  profileController.setTarget("C");
  profileController.waitUntilSettled();
}

void blueFlag1Print(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue, true);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue);

  drawLines(parent);

  defaultLeftCaps(parent);

  cap red_cap_1(parent, cap_position::right_1, cap_state::red);
  cap blue_cap_2(parent, cap_position::right_2, cap_state::blue_slanted);
  cap blue_cap_3(parent, cap_position::right_3, cap_state::blue, true);
  cap red_cap_4(parent, cap_position::right_4, cap_state::red);


  defaultLeftFlags(parent);
  defaultMiddleFlags(parent);

  flag right_top(parent, flag_position::right_high, flag_state::blue, true);
  flag right_mid(parent, flag_position::right_middle, flag_state::blue, true);
  flag right_low(parent, flag_position::right_low, flag_state::blue, true);

  drawFlagPoles(parent);

  defaultParking(parent);

  defaultLeftBalls(parent);
  defaultRightBalls(parent);
}

autonomousRoutine blueFlag1("Blue Flag - 11S", &blue_text, blueFlag1Auton, blueFlag1Print);


void redCap1Auton(){
  okapi::AsyncMotionProfileController profileController = okapi::AsyncControllerFactory::motionProfile(
    0.9,  // Maximum linear velocity of the Chassis in m/s
    1.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.3_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {2_ft, -1_ft, 0_deg}}, "B");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {5_ft, 0_ft, 0_deg}}, "C");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3_ft, 3_ft, 90_deg}}, "D");

  robot::scraper.moveAbsolute(30, 50);
  robot::intake.moveVoltage(12000);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  robot::intake.moveVoltage(0);
  robot::scraper.moveAbsolute(robot::capFlippingPosition, 50);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  profileController.setTarget("C", true);
  pros::delay(250);
  robot::scraper.moveAbsolute(30, 50);
  profileController.waitUntilSettled();

  profileController.setTarget("D");
  profileController.waitUntilSettled();

  robot::chassis.moveDistance(3_ft);
}

void redCap1Print(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red, true);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue);

  drawLines(parent);

  cap blue_cap_1(parent, cap_position::left_1, cap_state::red, true);
  cap red_cap_2(parent, cap_position::left_2, cap_state::red, true);
  cap red_cap_3(parent, cap_position::left_3, cap_state::red_slanted);
  cap blue_cap_4(parent, cap_position::left_4, cap_state::blue);
  defaultRightCaps(parent);

  defaultLeftFlags(parent);
  defaultMiddleFlags(parent);
  defaultRightFlags(parent);

  drawFlagPoles(parent);

  platform red_platform(parent, platform_color::red, true);
  platform blue_platform(parent, platform_color::blue);
  platform yellow_platform(parent, platform_color::yellow);

  lv_obj_t* ball_1 = lv_obj_create(parent, NULL);
  lv_obj_set_style(ball_1, &ball_style);
  lv_obj_set_pos(ball_1, 54, 54);
  lv_obj_set_size(ball_1, 5,5);

  lv_obj_t* ball_2 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_2, 60, 60);

  lv_obj_t* ball_5 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_5, 66, 122);

  lv_obj_t* ball_6 = lv_obj_create(parent, ball_1);
  lv_obj_set_pos(ball_6, 66, 153);

  defaultRightBalls(parent);
}

autonomousRoutine redCap1("Red Cap - 6S", &red_text, redCap1Auton, redCap1Print);


void blueCap1Auton(){
  okapi::AsyncMotionProfileController profileController = okapi::AsyncControllerFactory::motionProfile(
    0.9,  // Maximum linear velocity of the Chassis in m/s
    1.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.3_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {2_ft, 1_ft, 0_deg}}, "B");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {5_ft, 0_ft, 0_deg}}, "C");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3_ft, -3_ft, -90_deg}}, "D");

  robot::scraper.moveAbsolute(30, 50);
  robot::intake.moveVoltage(12000);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  robot::intake.moveVoltage(0);
  robot::scraper.moveAbsolute(robot::capFlippingPosition, 50);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  profileController.setTarget("C", true);
  pros::delay(250);
  robot::scraper.moveAbsolute(30, 50);
  profileController.waitUntilSettled();

  profileController.setTarget("D");
  profileController.waitUntilSettled();

  robot::chassis.moveDistance(3_ft);
}

void blueCap1Print(lv_obj_t* parent){
  starting_tile top_red_starting_tile(parent, starting_tile_position::far_red);
  starting_tile bottom_red_starting_tile(parent, starting_tile_position::near_red);
  starting_tile top_blue_starting_tile(parent, starting_tile_position::far_blue);
  starting_tile bottom_blue_starting_tile(parent, starting_tile_position::near_blue, true);

  drawLines(parent);

  defaultLeftCaps(parent);

  cap red_cap_1(parent, cap_position::right_1, cap_state::blue, true);
  cap blue_cap_2(parent, cap_position::right_2, cap_state::blue, true);
  cap blue_cap_3(parent, cap_position::right_3, cap_state::blue_slanted);
  cap red_cap_4(parent, cap_position::right_4, cap_state::red);


  defaultLeftFlags(parent);
  defaultMiddleFlags(parent);
  defaultRightFlags(parent);

  drawFlagPoles(parent);

  platform red_platform(parent, platform_color::red);
  platform blue_platform(parent, platform_color::blue, true);
  platform yellow_platform(parent, platform_color::yellow);

  defaultLeftBalls(parent);

  lv_obj_t* ball_3 = lv_obj_create(parent, NULL);
  lv_obj_set_style(ball_3, &ball_style);
  lv_obj_set_pos(ball_3, 174, 60);
  lv_obj_set_size(ball_3, 5,5);

  lv_obj_t* ball_4 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_4, 180, 54);

  lv_obj_t* ball_7 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_7, 170, 122);

  lv_obj_t* ball_8 = lv_obj_create(parent, ball_3);
  lv_obj_set_pos(ball_8, 170, 153);
}

autonomousRoutine blueCap1("Blue Cap - 6S", &blue_text, blueCap1Auton, blueCap1Print);

void skills1Auton(){
  okapi::AsyncMotionProfileController profileController = okapi::AsyncControllerFactory::motionProfile(
    0.9,  // Maximum linear velocity of the Chassis in m/s
    1.0,  // Maximum linear acceleration of the Chassis in m/s/s
    10.0, // Maximum linear jerk of the Chassis in m/s/s/s
    robot::chassis // Chassis Controller
  );

  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {3.8_ft, 0_in, 0_deg}}, "A");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {2_ft, 2_in, 0_deg}}, "B");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {4_ft, 6_in, 0_deg}}, "C");
  profileController.generatePath({{0_ft, 0_ft, 0_deg}, {6_ft, 0_in, 0_deg}}, "D");

  robot::scraper.moveAbsolute(30, 50);
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

  robot::scraper.moveAbsolute(0, 50);
  robot::chassis.turnAngle(-90_deg);

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  robot::intake.moveVoltage(0);
  robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);

  while(!robot::catapultLimit.isPressed()){
    pros::delay(10);
  }

  robot::catapult.moveVelocity(0);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  robot::chassis.turnAngle(90_deg);
  robot::chassis.moveDistance(-2_ft);

  robot::chassis.moveDistance(7_ft);
  pros::delay(200);
  robot::chassis.moveDistance(4_ft);
}

void skills1Print(lv_obj_t* parent){
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


  platform red_platform(parent, platform_color::red, true);
  platform blue_platform(parent, platform_color::blue);
  platform yellow_platform(parent, platform_color::yellow);

  defaultLeftBalls(parent);
  defaultRightBalls(parent);
}

autonomousRoutine skills1("Skills - 12", &white_text, skills1Auton, skills1Print);

std::vector<autonomousRoutine> autonomousRoutines = {disable, skills1, redFlag1, redCap1, blueFlag1, blueCap1};
