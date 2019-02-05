#include "main.h"
#include "autonomousSelect/autonomousRoutine.hpp"
#include "autonomousSelect/routines.hpp"
#include "autonomousSelect/screen.hpp"
#include "robot.hpp"
#include <vector>

void disableAutonomous(){}

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

autonomousRoutine disable("Disable", &white_text, disableAutonomous, disabledPrint);

std::vector<autonomousRoutine> autonomousRoutines = {disable};
