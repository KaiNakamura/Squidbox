#pragma once

#include <Arduino.h>
#include <BLEMidi.h>
#include "scene/Scene.h"
#include "scene/main/MainScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "scene/knob/KnobScene.h"
#include "config/config.h"
#include "config/pins.h"
#include "components/joystick/Joystick.h"
#include "components/knob/Knob.h"
#include "components/button/Button.h"

const int NUM_BUTTONS = 8;

class Squidbox
{
private:
  Scene *scenes[NUM_SCENES];
  int currentScene = KNOB_SCENE;

  Joystick *joystick;
  Knob *knob;
  Button *buttons[NUM_BUTTONS];

public:
  Squidbox();
  void init();
  void update();
  void switchTo(SceneType scene);
  Joystick *getJoystick();
  Knob *getKnob();
  Button **getButtons();
  Button *getButton(int index);
};