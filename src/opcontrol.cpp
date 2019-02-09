#include "main.h"
#include "robot.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	robot::catapult.tarePosition();

	bool catapultPositionHold = false;

	okapi::ControllerButton buttonR1 = robot::controller[okapi::ControllerDigital::R1];

	while(true){
    robot::chassis.tank(
      robot::controller.getAnalog(okapi::ControllerAnalog::leftY),
      robot::controller.getAnalog(okapi::ControllerAnalog::rightY));

		if(robot::controller.getDigital(okapi::ControllerDigital::X) || robot::catapultLimit.changedToReleased() || buttonR1.changedToPressed()){
			robot::catapult.tarePosition();
		}

    if(robot::controller.getDigital(okapi::ControllerDigital::R1)){
      robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);
			catapultPositionHold = false;
    }else if(catapultPositionHold){
      robot::catapult.moveAbsolute(robot::primedCatapultPosition, 200);
    }else{
			robot::catapult.moveVoltage(0);
		}

    if(robot::controller.getDigital(okapi::ControllerDigital::L1)){
      robot::intake.moveVoltage(12000);
			catapultPositionHold = true;
    }else if(robot::controller.getDigital(okapi::ControllerDigital::L2)){
			robot::intake.moveVoltage(-12000);
		}else{
      robot::intake.moveVoltage(0);
    }
/*
		if(robot::controller.getDigital(okapi::ControllerDigital::L1)){
      robot::scraper.moveVelocity(50);
    }else if(robot::controller.getDigital(okapi::ControllerDigital::L2)){
			robot::scraper.moveVelocity(-50);
		}else{
      robot::scraper.moveVelocity(0);
    }
*/
		pros::delay(10);
	}
}
