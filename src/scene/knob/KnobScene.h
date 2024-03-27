#pragma once

#include "scene/Scene.h"
#include "components/knob/Knob.h"

class KnobScene : public Scene
{
public:
  KnobScene(Squidbox *squidbox);
  void init();
  void update();
};