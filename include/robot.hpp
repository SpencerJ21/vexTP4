#ifndef ROBOT_HPP_
#define ROBOT_HPP_
#include "main.h"

using namespace okapi::literals;

namespace robot{
  //config declarations
  extern const double primedCatapultPosition;
  extern const double firingCatapultPosition;

  extern const double upwardScraperPosition;
  extern const double capFlippingPosition;
}


enum class screenMode{
  disabled, notification, selection, diagnostic, sans
};

namespace robot{
  //globals
  extern okapi::Motor intake;
  extern okapi::Motor scraper;
  extern okapi::MotorGroup catapult;
  extern okapi::ADIButton catapultLimit;
  extern okapi::ADIButton parkingLimit;
  extern okapi::ChassisControllerIntegrated chassis;
  extern okapi::Controller controller;

  namespace screen{
    extern pros::Task* controller;
    extern volatile screenMode state;
    extern std::string notification;
  };
};

#endif
