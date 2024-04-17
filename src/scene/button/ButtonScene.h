#pragma once

#include "scene/Scene.h"

class ButtonScene : public Scene {
public:
  ButtonScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};