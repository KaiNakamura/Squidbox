#pragma once

#include "scene/Scene.h"

class MainScene : public Scene
{
public:
  MainScene(Squidbox *squidbox);
  void init();
  void update();
};