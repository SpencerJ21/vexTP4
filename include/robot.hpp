#ifndef ROBOT_HPP_
#define ROBOT_HPP_
#include "main.h"

using namespace okapi::literals;

namespace robot{
  //config declarations
  extern const double primedCatapultPosition;
  extern const double firingCatapultPosition;

  extern const double upwardScraperPosition;
  extern const double ballScrapingPosition;
  extern const double capFlippingPosition;
}

namespace robot{
  //subsystems + controller
  extern okapi::Motor intake;
  extern okapi::Motor scraper;
  extern okapi::MotorGroup catapult;
  extern okapi::ADIButton catapultLimit;
  extern okapi::ADIButton catapultLimitBackup;
  extern okapi::ChassisControllerIntegrated chassis;
  extern okapi::Controller controller;
};

#endif
