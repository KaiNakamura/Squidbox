#pragma once

#include "scene/Scene.h"
#include "util/moving-average/MovingAverage.h"

class JoystickCalibratorScene : public Scene {
private:
  const int NUM_SAMPLES = 200;
  MovingAverage *xAverage, *yAverage;
  int xMin, yMin, xMax, yMax;

public:
  JoystickCalibratorScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};