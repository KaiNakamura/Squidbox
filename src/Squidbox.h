#pragma once

#include <Arduino.h>
#include <BLEMidi.h>
#include "scene/Scene.h"
#include "scene/main/MainScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "config/config.h"
#include "config/pins.h"
#include "components/joystick/Joystick.h"
#include "components/button/Button.h"

class Squidbox
{
private:
  Scene *scenes[NUM_SCENES];
  int currentScene = CHORD_SCENE;

  Joystick *joystick;
  Button *button1;
  Button *button2;
  Button *button3;
  Button *button4;
  Button *button5;
  Button *button6;
  Button *button7;
  Button *button8;

public:
  Squidbox();
  void init();
  void update();
  void switchTo(SceneType scene);
  Joystick *getJoystick();
  Button *getButton(int index);
};