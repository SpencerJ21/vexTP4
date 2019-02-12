#ifndef SLIPGEAR_CONTROLLER_HPP_
#define SLIPGEAR_CONTROLLER_HPP_
#include "main.h"

class Slipgear{
public:
  Slipgear(std::shared_ptr<okapi::MotorGroup> imotorPtr, double imotorToSlipGearing);

  void setTarget(double itarget, bool allowReverse = false);

  double getTarget();
  double getError();
  double getPosition();

  void tare();
  void checkForTare();
  void setDisabled(bool idisabled);
  bool isDisabled();

private:
  okapi::AsyncPosIntegratedController controller;
  std::shared_ptr<okapi::ContinuousRotarySensor> encoder;
  double motorToSlipGearing;
  double ceilingDegrees;
};

#endif
