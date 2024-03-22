#pragma once

#include <Arduino.h>
#include "config/config.h"
#include "config/pins.h"
#include "scene/SceneManager.h"

class Squidbox
{
private:
  SceneManager *sceneManager;

public:
  Squidbox();
  void update();
};