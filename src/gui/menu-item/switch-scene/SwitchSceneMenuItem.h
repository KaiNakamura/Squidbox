#pragma once

#include "gui/menu-item/MenuItem.h"
#include "scene/Scene.h"

class SwitchSceneMenuItem : public MenuItem {
private:
  Squidbox *squidbox;
  SceneType targetScene;
  static void onSelect(void *arg);

public:
  SwitchSceneMenuItem(const char *name, Squidbox *squidbox,
                      SceneType targetScene);
};