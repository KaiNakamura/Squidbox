#pragma once

#include "scene/Scene.h"
#include "util/Ascii.h"
#include "gui/menu/Menu.h"
#include "gui/menu-item/switch-scene/SwitchSceneMenuItem.h"

class MainScene : public Scene
{
public:
  MainScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};