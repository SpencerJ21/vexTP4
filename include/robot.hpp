#ifndef ROBOT_HPP_
#define ROBOT_HPP_
#include "main.h"
#include "slipgear.hpp"

using namespace okapi::literals;

namespace robot{
  //config declarations
  extern const double firingCatapultPosition;
  extern const double primedCatapultPosition;
}

namespace robot{
  //subsystems + controller
  extern okapi::Motor intake;
  extern okapi::Motor scraper;
  extern Slipgear catapult;
  extern okapi::ADIButton catapultLimit;
  extern okapi::ADIButton catapultLimitBackup;
  extern okapi::ChassisControllerIntegrated chassis;
  extern okapi::Controller controller;
};

#endif
