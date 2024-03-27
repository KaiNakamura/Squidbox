#pragma once

#include "scene/Scene.h"
#include "components/joystick/Joystick.h"
#include "util/moving-average/MovingAverage.h"

class JoystickCalibratorScene : public Scene
{
private:
  const int NUM_SAMPLES = 200;
  MovingAverage *xAverage, *yAverage;

public:
  JoystickCalibratorScene(Squidbox *squidbox);
  void init();
  void update();
};