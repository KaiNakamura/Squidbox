#pragma once

#include "gui/menu-item/switch-scene/SwitchSceneMenuItem.h"
#include "gui/menu/Menu.h"
#include "scene/Scene.h"
#include "util/Ascii.h"


class MainScene : public Scene {
public:
  MainScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};