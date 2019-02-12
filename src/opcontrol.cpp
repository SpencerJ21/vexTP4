#include "main.h"
#include "robot.hpp"
#include "slipgear.hpp"

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
	robot::catapult.tare();
	robot::catapult.setDisabled(true);

	okapi::ControllerButton buttonR1 = robot::controller[okapi::ControllerDigital::R1];

	while(true){
    robot::chassis.tank(
      robot::controller.getAnalog(okapi::ControllerAnalog::leftY),
      robot::controller.getAnalog(okapi::ControllerAnalog::rightY));


		if(robot::controller.getDigital(okapi::ControllerDigital::X) /*|| robot::catapultLimit.changedToReleased()*/){
			robot::catapult.tare();
		}

    if(robot::controller.getDigital(okapi::ControllerDigital::R1)){
      robot::catapult.setTarget(0);
    }else if(robot::catapult.getPosition() > 900){
			robot::catapult.setDisabled(true);
		}else{
      robot::catapult.setTarget(300);
    }

    if(robot::controller.getDigital(okapi::ControllerDigital::L1)){
      robot::intake.moveVoltage(12000);
			robot::catapult.setDisabled(false);
    }else if(robot::controller.getDigital(okapi::ControllerDigital::L2)){
			robot::intake.moveVoltage(-12000);
		}else{
      robot::intake.moveVoltage(0);
    }

		robot::catapult.checkForTare();

		std::cout << robot::catapult.getPosition() << " || " << robot::catapult.getTarget() << " || " << robot::catapult.isDisabled() << std::endl;
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
