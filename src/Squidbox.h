#pragma once

#include <Arduino.h>
#include "config/config.h"
#include "config/pins.h"
#include "scene/SceneManager.h"
#include "components/joystick/Joystick.h"

class Squidbox
{
private:
  SceneManager *sceneManager;
  Joystick *joystick;

public:
  Squidbox();
  void update();
};