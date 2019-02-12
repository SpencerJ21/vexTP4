#include "main.h"
#include "slipgear.hpp"

Slipgear::Slipgear(std::shared_ptr<okapi::MotorGroup> imotorPtr, double imotorToSlipGearing):
                  motorToSlipGearing(imotorToSlipGearing), controller(imotorPtr, okapi::TimeUtilFactory::create()), encoder(imotorPtr->getEncoder())
{
  imotorPtr->setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
  imotorPtr->setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  controller.setMaxVelocity(100);

  ceilingDegrees = 360 * imotorToSlipGearing;
}

void Slipgear::setTarget(double itarget, bool allowReverse){
  if(itarget > abs(encoder->get()) || allowReverse){
    controller.setTarget(itarget);
  }else{
    controller.setTarget(itarget + ceilingDegrees);
  }
}

double Slipgear::getTarget(){
  return controller.getTarget();
}

double Slipgear::getError(){
  return controller.getError();
}

double Slipgear::getPosition(){
  return encoder->get();
}

void Slipgear::tare(){
  encoder->reset();
}

void Slipgear::checkForTare(){
  if(encoder->get() > ceilingDegrees){
    tare();
  }
}

void Slipgear::setDisabled(bool idisabled){
  controller.flipDisable(idisabled);
}

bool Slipgear::isDisabled(){
  return controller.isDisabled();
}
