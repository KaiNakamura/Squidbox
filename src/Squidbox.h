#pragma once

#include "components/button/Button.h"
#include "components/joystick/Joystick.h"
#include "components/knob/Knob.h"
#include "components/screen/Screen.h"
#include "config/pins.h"
#include "scene/Scene.h"
#include "scene/button/ButtonScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/drum/DrumScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "scene/knob/KnobScene.h"
#include "scene/main/MainScene.h"
#include "scene/note/NoteScene.h"
#include <Arduino.h>
#include <BLEMidi.h>
#include <esp_efuse.h>


const int NUM_BUTTONS = 8;

class Squidbox {
private:
  Scene *scenes[NUM_SCENES];
  int currentScene = MAIN_SCENE;
  Screen *screen;
  Joystick *joystick;
  Knob *knob;
  Button *backButton;
  Button *okButton;
  Button *buttons[NUM_BUTTONS];
  bool currentSceneInitialized = false;

public:
  Squidbox();
  void init();
  void update();
  void switchTo(SceneType scene);
  void sleep();
  Screen *getScreen();
  Joystick *getJoystick();
  Knob *getKnob();
  Button *getBackButton();
  Button *getOkButton();
  Button **getButtons();
  Button *getButton(int index);
  const char *getDeviceId();
  const char *getName();
};