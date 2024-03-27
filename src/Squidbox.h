#pragma once

#include <Arduino.h>
#include "scene/Scene.h"
#include "scene/main/MainScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "config/config.h"
#include "config/pins.h"
#include "components/joystick/Joystick.h"

class Squidbox
{
private:
  Scene *scenes[NUM_SCENES];
  int currentScene = JOYSTICK_CALIBRATOR_SCENE;

  Joystick *joystick;

public:
  Squidbox();
  void init();
  void update();
  void switchTo(SceneType scene);
  Joystick *getJoystick();
};