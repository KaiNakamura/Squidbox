#pragma once

#include "SceneType.h"

const int NUM_SCENES = 5;

class Squidbox;

class Menu;

class Scene {
protected:
  SceneType type;
  Squidbox *squidbox;
  Menu *menu;

public:
  Scene(Squidbox *squidbox, Menu *menu);
  Squidbox *getSquidbox();
  virtual void init();
  virtual void update();
};