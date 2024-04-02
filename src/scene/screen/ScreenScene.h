#pragma once

#include "scene/Scene.h"
#include "components/screen/Screen.h"

class ScreenScene : public Scene
{
public:
  ScreenScene(Squidbox *squidbox);
  void init();
  void update();
};