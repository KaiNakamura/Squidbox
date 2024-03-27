#pragma once

#include "scene/Scene.h"
#include "components/joystick/Joystick.h"

class JoystickCalibratorScene : public Scene
{
private:
  const float ALPHA = 0.999;
  Joystick *joystick;
  float xAccumulator;
  float yAccumulator;

public:
  JoystickCalibratorScene(Squidbox *squidbox);
  void init();
  void update();
};