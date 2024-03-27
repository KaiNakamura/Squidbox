#include "JoystickCalibratorScene.h"
#include "Squidbox.h"

JoystickCalibratorScene::JoystickCalibratorScene(Squidbox *squidbox)
{
  type = JOYSTICK_CALIBRATOR_SCENE;
  this->squidbox = squidbox;
}

void JoystickCalibratorScene::init()
{
  joystick = squidbox->getJoystick();
  xAccumulator = joystick->getRawX();
  yAccumulator = joystick->getRawY();
}

void JoystickCalibratorScene::update()
{
  xAccumulator = (ALPHA * joystick->getRawX()) + (1.0 - ALPHA) * xAccumulator;
  yAccumulator = (ALPHA * joystick->getRawY()) + (1.0 - ALPHA) * yAccumulator;
  Serial.printf("(%.0f, %.0f)\n", xAccumulator, yAccumulator);
}