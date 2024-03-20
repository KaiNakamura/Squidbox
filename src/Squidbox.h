#pragma once

#include <Arduino.h>
#include "config/config.h"
#include "config/pins.h"
#include "Scene.h"

class Squidbox
{
private:
  Scene *scenes;

public:
  Squidbox();
  void setup();
  void loop();
};