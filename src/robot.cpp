#include "main.h"
#include "robot.hpp"

using namespace okapi::literals;


namespace robot{
  //user defined config
  const double primedCatapultPosition = 1.0;
  const double firingCatapultPosition = 3.5;
}

//robot initialization

okapi::Motor robot::intake(16);

okapi::Motor robot::scraper(0);

okapi::MotorGroup robot::catapult({20, -17});
okapi::ADIButton robot::catapultLimit(1);
okapi::ADIButton robot::catapultLimitBackup(2);

okapi::ChassisControllerIntegrated robot::chassis = okapi::ChassisControllerFactory::create(
  {-11, 19},   // Left motors
  {15, -18},    // Right motors
  okapi::AbstractMotor::gearset::green, // 200RPM gearset
  {4.188_in, 12.5_in} // 4.15 inch wheels (4 inch omnis are slightly larger), 12.5 inch wheelbase width
);

//main controller
okapi::Controller robot::controller(okapi::ControllerId::master);
