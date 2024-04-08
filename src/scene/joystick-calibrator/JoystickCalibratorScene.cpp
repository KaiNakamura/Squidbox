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
  xMin = 4096;
  yMin = 4096;
  xMax = -1;
  yMax = -1;
}

void JoystickCalibratorScene::update()
{
  Joystick *joystick = squidbox->getJoystick();
  int rawX = joystick->getRawX();
  int rawY = joystick->getRawY();
  if (rawX < xMin)
  {
    xMin = rawX;
  }
  else if (rawX > xMax)
  {
    xMax = rawX;
  }

  if (rawY < yMin)
  {
    yMin = rawY;
  }
  else if (rawY > yMax)
  {
    yMax = rawY;
  }

  float averageX = xAverage->next(joystick->getRawX());
  float averageY = yAverage->next(joystick->getRawY());
  float x = joystick->getX();
  float y = joystick->getY();
  Direction direction = joystick->getDirection();
  Serial.printf(
      "raw: (%.0f, %.0f), xRange: [%d, %d], yRange: [%d, %d], (x, y): (%.2f, %.2f) %s\n",
      averageX, averageY, xMin, xMax, yMin, yMax, x, y, directionToString(direction));
}