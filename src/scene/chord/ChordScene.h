#pragma once

#include "scene/Scene.h"

class ChordScene : public Scene
{
public:
  ChordScene(Squidbox *squidbox);
  void init();
  void update();
};