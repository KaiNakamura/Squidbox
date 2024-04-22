#pragma once

#include "SceneType.h"

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