#include "JoystickCalibratorScene.h"
#include "Squidbox.h"

JoystickCalibratorScene::JoystickCalibratorScene(Squidbox *squidbox) : Scene(squidbox, nullptr)
{
  type = JOYSTICK_CALIBRATOR_SCENE;
  menu = new Menu("Joystick Calibrator", MAIN_SCENE);
}

void JoystickCalibratorScene::init()
{
  Scene::init();
  xAverage = new MovingAverage(NUM_SAMPLES);
  yAverage = new MovingAverage(NUM_SAMPLES);
  xMin = 4096;
  yMin = 4096;
  xMax = -1;
  yMax = -1;
}

void JoystickCalibratorScene::update()
{
  Scene::update();
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