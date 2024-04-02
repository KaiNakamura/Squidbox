#pragma once

#include <Arduino.h>
#include <BLEMidi.h>
#include "scene/Scene.h"
#include "scene/main/MainScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/screen/ScreenScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "scene/knob/KnobScene.h"
#include "scene/button/ButtonScene.h"
#include "config/config.h"
#include "config/pins.h"
#include "components/screen/Screen.h"
#include "components/joystick/Joystick.h"
#include "components/knob/Knob.h"
#include "components/button/Button.h"

const int NUM_BUTTONS = 8;

class Squidbox
{
private:
  Scene *scenes[NUM_SCENES];
  int currentScene = SCREEN_SCENE;

  Screen *screen;
  Joystick *joystick;
  Knob *knob;
  Button *backButton;
  Button *okButton;
  Button *buttons[NUM_BUTTONS];

public:
  Squidbox();
  void init();
  void update();
  void switchTo(SceneType scene);
  Screen *getScreen();
  Joystick *getJoystick();
  Knob *getKnob();
  Button *getBackButton();
  Button *getOkButton();
  Button **getButtons();
  Button *getButton(int index);
};