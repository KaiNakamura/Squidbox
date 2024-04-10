#pragma once

const int NUM_SCENES = 6;

enum SceneType
{
  MAIN_SCENE,
  CHORD_SCENE,
  SCREEN_SCENE,
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
  // TODO: Make constructor
  Squidbox *getSquidbox();
  virtual void init();
  virtual void update();
};