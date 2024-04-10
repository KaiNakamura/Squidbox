#pragma once

#include "scene/Scene.h"
#include "util/Ascii.h"
#include "gui/menu/Menu.h"

class MainScene : public Scene
{
private:
  Menu *menu;
  static void switchToChordScene(Scene *scene);

public:
  MainScene(Squidbox *squidbox);
  void init();
  void update();
};