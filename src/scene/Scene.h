#pragma once

#include <Arduino.h>

const int NUM_SCENES = 2;

enum SceneType
{
  MAIN_SCENE,
  CHORD_SCENE,
};

class Scene
{
protected:
  SceneType type;

public:
  virtual void init();
  virtual void update();
};