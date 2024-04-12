#pragma once

#include "scene/Scene.h"
#include "util/Ascii.h"
#include "gui/menu/Menu.h"

class MainScene : public Scene
{
private:
  static void switchToChordScene(Scene *scene);
  static void switchToJoystickCalibratorScene(Scene *scene);

public:
  MainScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};