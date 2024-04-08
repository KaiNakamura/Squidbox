#include "JoystickCalibratorScene.h"
#include "Squidbox.h"

JoystickCalibratorScene::JoystickCalibratorScene(Squidbox *squidbox)
{
  type = JOYSTICK_CALIBRATOR_SCENE;
  this->squidbox = squidbox;
}

void JoystickCalibratorScene::init()
{
  xAverage = new MovingAverage(NUM_SAMPLES);
  yAverage = new MovingAverage(NUM_SAMPLES);
}

void JoystickCalibratorScene::update()
{
  Joystick *joystick = squidbox->getJoystick();

  if (joystick->isPressed())
  {
    init();
  }

  float rawX = xAverage->next(joystick->getRawX());
  float rawY = yAverage->next(joystick->getRawY());
  float x = joystick->getX();
  float y = joystick->getY();
  Direction direction = joystick->getDirection();
  Serial.printf("(rawX, rawY): (%.0f, %.0f), (x, y): (%.2f, %.2f), %s\n", rawX, rawY, x, y, directionToString(direction));
}