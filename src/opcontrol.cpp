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
	robot::chassis.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

	robot::catapult.tarePosition();

	okapi::ControllerButton buttonR2 = robot::controller[okapi::ControllerDigital::R2];
	okapi::ControllerButton buttonY = robot::controller[okapi::ControllerDigital::Y];

	robot::scraper.moveAbsolute(90, 50);

	bool catapultEnabled = false;
	bool scraperUp = true;
	bool braking = false;
	uint count = 0;

	while(true){

		if(buttonY.changedToPressed()){
			braking = !braking;

			robot::chassis.setBrakeMode(braking ? okapi::AbstractMotor::brakeMode::hold : okapi::AbstractMotor::brakeMode::coast);
		}

    robot::chassis.tank(
      robot::controller.getAnalog(okapi::ControllerAnalog::leftY),
      robot::controller.getAnalog(okapi::ControllerAnalog::rightY));

		//user input of catapult controller
		if(robot::controller.getDigital(okapi::ControllerDigital::X)){
			robot::catapult.tarePosition();
		}

		if(robot::controller.getDigital(okapi::ControllerDigital::A)){
			catapultEnabled = true;
		}else if(robot::controller.getDigital(okapi::ControllerDigital::B)){
			catapultEnabled = false;
		}

		//smart catapult auto input
		if(robot::catapultLimit.changed()){
			if(robot::catapultLimit.isPressed()){
				//rising edge
				catapultEnabled = false;
			}else{
				//falling edge
				robot::catapult.tarePosition();
			}
		}

		if(catapultEnabled){
    	if(robot::controller.getDigital(okapi::ControllerDigital::R1) || robot::catapultLimit.isPressed()){
      	robot::catapult.moveAbsolute(robot::firingCatapultPosition, 200);
    	}else{
      	robot::catapult.moveAbsolute(robot::primedCatapultPosition, 200);
    	}
		}else{
			robot::catapult.moveVelocity(0);
		}


    if(robot::controller.getDigital(okapi::ControllerDigital::L1) && scraperUp){
      robot::intake.moveVoltage(12000);
			catapultEnabled = true;
    }else if(robot::controller.getDigital(okapi::ControllerDigital::L2) && scraperUp){
			robot::intake.moveVoltage(-12000);
		}else{
      robot::intake.moveVoltage(0);
    }


		if(robot::controller.getDigital(okapi::ControllerDigital::up)){
			scraperUp = true;
			robot::scraper.moveAbsolute(robot::upwardScraperPosition, 50);

		}else if(robot::controller.getDigital(okapi::ControllerDigital::down)){
			scraperUp = false;
			robot::scraper.moveAbsolute(robot::capFlippingPosition, 50);

		}else if(robot::controller.getDigital(okapi::ControllerDigital::right)){
			robot::scraper.moveAbsolute(90, 50);

		}else if(buttonR2.changedToPressed()){
			scraperUp = !scraperUp;

			if(scraperUp){
				robot::scraper.moveAbsolute(robot::upwardScraperPosition, 50);
			}else{
				robot::scraper.moveAbsolute(robot::capFlippingPosition, 50);
			}
		}


		if(!(count % 40)){
			robot::controller.setText(0, 0, std::to_string(robot::catapult.getTemperature()) + (braking ? " B" : " C"));
		}

		count++;
		pros::delay(10);
	}
}
