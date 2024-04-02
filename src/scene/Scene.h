#pragma once

const int NUM_SCENES = 5;

enum SceneType
{
  MAIN_SCENE,
  CHORD_SCENE,
  JOYSTICK_CALIBRATOR_SCENE,
  KNOB_SCENE,
  BUTTON_SCENE,
};

class Squidbox;

class Scene
{
protected:
  SceneType type;
  Squidbox *squidbox;

public:
  virtual void init();
  virtual void update();
};